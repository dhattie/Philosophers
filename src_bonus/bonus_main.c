/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:22:00 by dhattie           #+#    #+#             */
/*   Updated: 2022/01/16 14:22:03 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_philo.h"

void	sem_inits(t_philosof *p)
{
	sem_unlink("forks");
	sem_unlink("message");
	sem_unlink("change_ph_data");
	p->fork = sem_open("forks", O_CREAT | O_EXCL, 0666, p->param->num_of_ph);
	p->message = sem_open("message", O_CREAT | O_EXCL, 0666, 1);
	p->change_ph_data = sem_open("change_ph_data", O_CREAT | O_EXCL, 0666, 1);
}

int	treads_start(void *philo)
{
	pthread_t	death;
	t_philosof	*ph;

	ph = (t_philosof *)philo;
	if (pthread_create(&death, NULL, check_philo, ph))
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (!param)
		return (print_err(3));
	if (argc != 5 && argc != 6)
		return (print_err(1));
	if (check_argv(argv) == -1)
		return (print_err(2));
	if (param_push(argc, argv, param) == -1)
		return (print_err(2));
	if (create_philosofs(param) == -1)
		return (print_err(3));
	return (0);
}
