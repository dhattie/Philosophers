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

#include "../includes/bonus_philo.h"

void	*philo_action(void *philo)
{
	t_philosof	*tmp;

	tmp = philo;
	if (!(tmp->id % 2))
		usleep(300);
	treads_start(tmp);
	while (1)
		take_forks(philo);
	return (NULL);
}

void	take_forks(t_philosof *philo)
{
	sem_wait(philo->fork);
	philo_messages(T_R_FORK, philo);
	sem_wait(philo->fork);
	philo_messages(T_L_FORK, philo);
	eating(philo);
}

void	eating(t_philosof *philo)
{
	philo_messages(EATING, philo);
	sem_wait(philo->change_ph_data);
	philo->t_last_meal = get_time();
	philo->number_meals++;
	if (philo->number_meals == philo->param->ph_num_to_eat
		&& philo->param->ph_num_to_eat > 0)
	{
		sem_post(philo->param->all_eaten);
	}
	sem_post(philo->change_ph_data);
	p_usleep(philo->param->t_to_eat);
	sem_post(philo->fork);
	sem_post(philo->fork);
	sleeping(philo);
}

void	*check_philo(void *philo)
{
	t_philosof	*tmp;
	int			difference;

	tmp = (t_philosof *)philo;
	while (1)
	{
		sem_wait(tmp->change_ph_data);
		difference = get_time() - tmp->t_last_meal;
		sem_post(tmp->change_ph_data);
		if ((difference) >= tmp->param->t_to_die)
			philo_messages(DEATH, philo);
		usleep(100);
	}
	return (NULL);
}

void	philo_messages(int i, t_philosof *philo)
{
	int		a;
	int		b;
	t_forks	*message;

	a = get_time() - philo->param->time_start;
	b = philo->id;
	message = philo->message;
	sem_wait(message);
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
		exit(1);
	}
	sem_post(message);
}
