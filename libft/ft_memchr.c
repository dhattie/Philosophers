/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 12:02:28 by dhattie           #+#    #+#             */
/*   Updated: 2021/05/01 12:02:31 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Search for the first occurrence of a character in an array.

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*copy_s;
	size_t			i;

	copy_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (copy_s[i] == (unsigned char)c)
			return (&copy_s[i]);
		i++;
	}
	return (NULL);
}
