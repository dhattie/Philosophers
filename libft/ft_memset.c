/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 14:03:44 by dhattie           #+#    #+#             */
/*   Updated: 2021/05/01 14:03:46 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memset () function fills the first n bytes of the
memory area pointed to by s with a constant byte c.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;

	p = (char *)b;
	while (len > 0)
	{
		p [len - 1] = c;
		len--;
	}
	return (b);
}
