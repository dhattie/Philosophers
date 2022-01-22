/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:44:44 by dhattie           #+#    #+#             */
/*   Updated: 2021/05/03 19:44:46 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The strlcpy function copies no more than size - 1 characters
from the src string to the dst buffer and is guaranteed to 
set a null character to the end of the string.

strlcpy returns the size of the string at src. strlcat returns
the total length of strings at src and dst addresses. The return
value does not depend on whether the entire string was copied or
not; this makes it easy to determine that the destination buffer
is too small for the line being copied.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	if (!dest && !src)
		return (0);
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
