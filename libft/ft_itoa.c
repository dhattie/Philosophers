/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:47:26 by dhattie           #+#    #+#             */
/*   Updated: 2021/05/03 19:47:31 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc) and returns a string representing the
integer received as an argument. Negative numbers must be handled
*/

#include "libft.h"

size_t	len(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char	*number;
	int		len_n;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len_n = len(nb);
	number = (char *)malloc(sizeof(char) * len_n + 1);
	if (!number)
		return (NULL);
	number[len_n] = '\0';
	if (nb == 0)
		number[0] = '0';
	if (nb < 0)
	{
		number[0] = '-';
		nb = nb * -1;
	}
	while (nb)
	{
		len_n--;
		number[len_n] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (number);
}
