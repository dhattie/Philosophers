/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:33:53 by dhattie           #+#    #+#             */
/*   Updated: 2021/05/01 13:33:55 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*copy_dst;
	unsigned char	*copy_src;
	size_t			i;

	copy_dst = (unsigned char *)dst;
	copy_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		copy_dst[i] = copy_src[i];
		if (copy_dst[i] == (unsigned char)c)
			return ((void *)(&dst[i + 1]));
		i++;
	}
	return (NULL);
}
