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

#include "../includes/bonus_philo.h"

int	create_philosofs(t_param *param)
{
	t_philosof	*philo;

	philo = malloc(sizeof (t_philosof));
	philo->pid = malloc(sizeof (pid_t) * param->num_of_ph);
	if (!philo || !philo->pid)
		return (-1);
	philo->t_last_meal = get_time();
	philo->number_meals = 0;
	philo->param = param;
	sem_inits(philo);
	init_philosofs(philo, param);
	return (0);
}

int	init_philosofs(t_philosof *philo, t_param *param)
{
	int	i;

	i = -1;
	while (++i < param->num_of_ph)
	{
		philo->id = i + 1;
		philo->pid[i] = fork();
		if (!philo->pid[i])
			philo_action(philo);
	}
	finish(param, philo);
	return (0);
}

void	finish(t_param *param, t_philosof *philo)
{
	int		j;
	int		status;

	j = -1;
	status = 0;
	while (++j < param->num_of_ph)
	{
		waitpid(0, &status, 0);
		kill(philo->pid[j], SIGKILL);
	}
	sem_close(philo->fork);
	sem_close(philo->message);
	exit(0);
}

int	param_push(int argc, char **argv, t_param *param)
{
	param->time_start = get_time();
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
