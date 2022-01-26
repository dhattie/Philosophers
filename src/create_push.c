/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:22:23 by dhattie           #+#    #+#             */
/*   Updated: 2022/01/16 14:22:24 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	create_philosofs(t_param *param)
{
	t_philosof	**phils;
	t_forks		**ph_forks;
	int			i;

	phils = (t_philosof **) malloc(sizeof (t_philosof *) * param->num_of_ph);
	ph_forks = (t_forks **) malloc(sizeof (t_forks) * param->num_of_ph);
	if (!phils || !ph_forks)
		return (-1);
	i = -1;
	while (++i < param->num_of_ph)
	{
		phils[i] = (t_philosof *) malloc(sizeof (t_philosof));
		ph_forks[i] = (t_forks *) malloc(sizeof (t_forks));
		phils[i]->change_ph_data = malloc(sizeof (t_forks));
		pthread_mutex_init(phils[i]->change_ph_data, NULL);
		if (!phils[i] || !ph_forks[i])
			return (-1);
		pthread_mutex_init(ph_forks[i], NULL);
	}
	init_philosofs(phils, param, ph_forks);
	if ((create_threads(phils, param, ph_forks) < 0))
		return (-1);
	usleep(500);
	return (0);
}

int	init_philosofs(t_philosof **phils, t_param *param, t_forks **ph_forks)
{
	int	i;

	i = -1;
	while (++i < param->num_of_ph)
	{
		phils[i]->t_last_meal = get_time();
		phils[i]->number_meals = 0;
		phils[i]->id = i + 1;
		phils[i]->right_fork = NULL;
		phils[i]->left_fork = NULL;
		if (param->num_of_ph == 1)
			phils[0]->right_fork = ph_forks[0];
		else
		{
			phils[i]->right_fork = ph_forks[i];
			if (i + 1 == param->num_of_ph)
				phils[i]->left_fork = ph_forks[0];
			else
				phils[i]->left_fork = ph_forks[i + 1];
		}
		phils[i]->param = param;
	}
	return (0);
}

int	create_threads(t_philosof **phils, t_param *param, t_forks **ph_forks)
{
	int			i;
	pthread_t	*philo_threads;

	param->time_start = get_time();
	i = -1;
	philo_threads = (pthread_t *)malloc(sizeof(pthread_t) * param->num_of_ph);
	while (++i < param->num_of_ph)
	{
		if (pthread_create(philo_threads + i, NULL, philo_action, phils[i]))
			return (-1);
		if (pthread_detach(philo_threads[i]))
			return (-1);
	}
	if (pthread_create(&param->death, NULL, check_phils, phils))
		return (-1);
	if (pthread_join(param->death, NULL))
		return (-1);
	usleep(1000);
	free(philo_threads);
	philo_threads = NULL;
	free_all(phils, param, ph_forks);
	return (0);
}

int	param_push(int argc, char **argv, t_param *param)
{
	pthread_mutex_init(param->mutex, NULL);
	param->num_of_ph = int_size(ft_atoi(argv[1]));
	param->t_to_die = int_size(ft_atoi(argv[2]));
	param->t_to_eat = int_size(ft_atoi(argv[3]));
	param->t_to_sleep = int_size(ft_atoi(argv[4]));
	param->ph_num_to_eat = 0;
	if (argc == 6)
		param->ph_num_to_eat = int_size(ft_atoi(argv[5]));
	if (param->num_of_ph > 200 || param->num_of_ph < 1 || param->t_to_die < 1
		|| param->t_to_eat < 1 || param->t_to_sleep < 1)
		return (-1);
	if (argc == 6 && param->ph_num_to_eat < 1)
		return (-1);
	return (0);
}
