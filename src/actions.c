/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:23:26 by dhattie           #+#    #+#             */
/*   Updated: 2022/01/16 14:23:28 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_action(void *philo)
{
	t_philosof	*tmp;

	tmp = philo;
	if (!(tmp->id % 2))
		usleep(50);
	while (1)
		take_forks(philo);
	return (NULL);
}

void	take_forks(t_philosof *philo)
{
	if (philo->right_fork != NULL)
	{
		pthread_mutex_lock(philo->right_fork);
		philo_messages(T_R_FORK, philo);
		if (philo->left_fork != NULL)
		{
			pthread_mutex_lock(philo->left_fork);
			philo_messages(T_L_FORK, philo);
			eating(philo);
		}
	}
}

int	eating(t_philosof *philo)
{
	philo_messages(EATING, philo);
	pthread_mutex_lock(philo->change_ph_data);
	philo->t_last_meal = get_time();
	philo->number_meals++;
	pthread_mutex_unlock(philo->change_ph_data);
	p_usleep(philo->param->t_to_eat);
	if (philo->right_fork)
		pthread_mutex_unlock(philo->right_fork);
	if (philo->left_fork)
		pthread_mutex_unlock(philo->left_fork);
	sleeping(philo);
	return (0);
}

void	sleeping(t_philosof *philo)
{
	philo_messages(SLEEPING, philo);
	p_usleep(philo->param->t_to_sleep);
	philo_messages(THINKING, philo);
}

void	philo_messages(int i, t_philosof *philo)
{
	int		a;
	int		b;
	t_forks	*mutex;

	b = philo->id;
	a = get_time() - philo->param->time_start;
	mutex = philo->param->mutex;
	pthread_mutex_lock(mutex);
	if (i == T_R_FORK)
		printf("%d [%d]  has taken a right fork\n", a, b);
	else if (i == T_L_FORK)
		printf("%d [%d]  has taken a left fork\n", a, b);
	else if (i == EATING)
		printf("%d [%d] %s eating %s\n", a, b, COLOR_YELLOW, COLOR_END);
	else if (i == SLEEPING)
		printf("%d [%d] %s sleeping %s\n", a, b, COLOR_BLUE, COLOR_END);
	else if (i == THINKING)
		printf("%d [%d] %s thinking %s\n", a, b, COLOR_GREEN, COLOR_END);
	else if (i == DEATH)
	{
		printf("%d [%d] %s died %s\n", a, b, COLOR_RED, COLOR_END);
		return ;
	}
	pthread_mutex_unlock(mutex);
}
