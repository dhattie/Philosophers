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

#include "../includes/bonus_philo.h"

int	print_err(int err)
{
	if (err == 1)
		printf("Incorrect number of arguments\n");
	else if (err == 2)
		printf("Use positive numbers type int, the number of phil <= 200\n");
	else if (err == 3)
		printf("The program was not executed\n");
	return (-1);
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

void	sleeping(t_philosof *philo)
{
	philo_messages(SLEEPING, philo);
	p_usleep(philo->param->t_to_sleep);
	philo_messages(THINKING, philo);
}
