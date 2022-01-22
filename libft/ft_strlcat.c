/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 11:02:35 by dhattie           #+#    #+#             */
/*   Updated: 2021/05/01 11:02:40 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
strlcat copies src to dst, but copies to the end of
dst so that it continues on the line pointed to by dst.
and return len dest after + src
*/

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	j = 0;
	if (!dest)
		abort();
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (size < len_dest)
		len_src = len_src + size;
	else
		len_src = len_src + len_dest;
	while (src[j] && len_dest < size - 1)
	{
		dest[len_dest] = src[j];
		j++;
		len_dest++;
	}
	dest[len_dest] = 0;
	return (len_src);
}
