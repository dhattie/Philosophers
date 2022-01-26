/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:00:34 by dhattie           #+#    #+#             */
/*   Updated: 2022/01/21 20:00:38 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h> /** malloc, free, exit*/
# include <sys/time.h> /** for gettimeofday */
# include <unistd.h> /** read, close, write*/
# include <stdio.h> /** printf, perror */
# include <pthread.h>
# include <string.h>
# include "../libft/libft.h"

# define T_L_FORK	1
# define T_R_FORK	2
# define EATING		3
# define SLEEPING	4
# define THINKING	5
# define DEATH		6

# define COLOR_RED		"\33[31m"
# define COLOR_BLUE		"\33[34m"
# define COLOR_GREEN	"\33[32m"
# define COLOR_YELLOW	"\33[93m"
# define COLOR_END		"\33[0m"

typedef pthread_mutex_t	t_forks;

typedef struct s_param
{
	pthread_t	death;
	int			num_of_ph;
	int			t_to_die;
	int			t_to_eat;
	int			t_to_sleep;
	int			ph_num_to_eat;
	int			time_start;
	t_forks		*mutex;
}				t_param;

typedef struct s_philosof
{
	int			id;
	t_forks		*left_fork;
	t_forks		*right_fork;
	t_forks		*change_ph_data;
	t_param		*param;
	int			t_last_meal;
	int			number_meals;
}				t_philosof;

/** create objects and populate data */
int		create_philosofs(t_param *param);
int		init_philosofs(t_philosof **phils, t_param *param, t_forks **ph_forks);
int		param_push(int argc, char **argv, t_param *param);
int		create_threads(t_philosof **phils, t_param *param, t_forks **ph_forks);

/** actions */
void	take_forks(t_philosof *philo);
void	*philo_action(void *philo);
void	sleeping(t_philosof *philo);
int		eating(t_philosof *philo);
void	philo_messages(int i, t_philosof *philo);

/** cheks */
int		check_argv(char **argv);
void	*check_phils(void *phils);
int		check_n_fat_phils(t_philosof **philos);

/** utils */
int		print_err(int err);
int		int_size(int num);
int		get_time(void);
void	p_usleep(int time);
int		free_all(t_philosof **phils, t_param *param, t_forks **ph_forks);

#endif