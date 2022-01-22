/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:22:34 by dhattie           #+#    #+#             */
/*   Updated: 2022/01/16 14:22:36 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_err(int err)
{
	if (err == 1)
		printf("Incorrect number of arguments\n");
	else if (err == 2)
		printf("Use positive numbers type int, the number of phil <= 200\n");
	else if (err == 3)
		printf("The program was not executed\n");
	exit(-1);
}

int	int_size(int num)
{
	if (num < -2147483648 || num > 2147483647)
		return (-1);
	return (num);
}

int	get_time(void)
{
	struct timeval	timeval;
	int				time;

	gettimeofday(&timeval, NULL);
	time = (int)(timeval.tv_sec * 1000 + timeval.tv_usec / 1000);
	return (time);
}

void	p_usleep(int time)
{
	time_t	start;
	time_t	stop;

	stop = get_time() + time;
	start = get_time();
	while (start < stop)
	{
		usleep(50);
		start = get_time();
	}
}

int	free_all(t_philosof **phils, t_param *param, t_forks **ph_forks)
{
	int	i;

	pthread_mutex_destroy(param->mutex);
	i = -1;
	while (++i < param->num_of_ph)
	{
		pthread_mutex_destroy(ph_forks[i]);
		free(phils[i]);
		phils[i] = NULL;
		free(ph_forks[i]);
		ph_forks[i] = NULL;
	}
	free(phils);
	phils = NULL;
	free(param);
	param = NULL;
	free(ph_forks);
	ph_forks = NULL;
	return (0);
}
