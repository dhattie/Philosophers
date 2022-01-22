/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:22:11 by dhattie           #+#    #+#             */
/*   Updated: 2022/01/16 14:22:13 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (-1);
		}
	}
	return (0);
}

void	*check_phils(void *phils)
{
	int				i;
	t_philosof		**tmp;
	int				difference;

	tmp = phils;
	i = 0;
	while (1)
	{
		if (i >= tmp[0]->param->num_of_ph)
			i = 0;
		if (check_n_fat_phils(tmp) < 0)
			return ((void *) -1);
		difference = get_time() - tmp[i]->t_last_meal;
		if ((difference) > tmp[i]->param->t_to_die)
		{
			philo_messages(DEATH, tmp[i]);
			return ((void *) -1);
		}
		i++;
		usleep(100);
	}
}

int	check_n_fat_phils(t_philosof **tmp)
{
	int	i;
	int	n_fat_phils;
	int	num_of_ph;
	int	ph_num_to_eat;

	ph_num_to_eat = tmp[0]->param->ph_num_to_eat;
	num_of_ph = tmp[0]->param->num_of_ph;
	i = -1;
	n_fat_phils = 0;
	while ((++i < num_of_ph) && ph_num_to_eat)
	{
		if (tmp[i]->number_meals >= ph_num_to_eat)
			n_fat_phils++;
		if ((n_fat_phils >= num_of_ph))
			return (-1);
	}
	return (0);
}
