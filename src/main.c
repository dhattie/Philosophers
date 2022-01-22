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

#include "../includes/philo.h"

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
