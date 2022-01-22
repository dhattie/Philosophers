/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:27:39 by dhattie           #+#    #+#             */
/*   Updated: 2021/04/29 20:27:42 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Convert a string to a integer :)

#include "libft.h"

static int	big_int(long long int num, int len_num, int simbol)
{
	if (len_num > 19 && simbol == 1)
		return (-1);
	if (len_num > 19 && simbol == -1)
		return (0);
	if (num > 9223372036854775807 && simbol == -1)
		return (-1);
	if (num > 9223372036854775807 && simbol == 1)
		return (0);
	return ((int) num * simbol);
}

int	ft_atoi(const char *str)
{
	long long int	num;
	int				simbol;
	int				i;
	int				len_num;

	i = 0;
	simbol = 1;
	num = 0;
	len_num = 0;
	while ((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		simbol = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		len_num++;
		i++;
	}
	return (big_int(num, len_num, simbol));
}
