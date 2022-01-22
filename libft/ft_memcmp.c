/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 11:48:52 by dhattie           #+#    #+#             */
/*   Updated: 2021/05/01 11:48:54 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memcmp () function compares the first count characters of the arrays pointed
to by s1 and s2. The comparison is made lexicographically. The memcmp () 
function returns difference
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*copy_s1;
	unsigned char	*copy_s2;
	int				i;

	i = 0;
	copy_s1 = (unsigned char *)s1;
	copy_s2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (--n && copy_s1[i] == copy_s2[i])
		i++;
	return ((int)(copy_s1[i] - copy_s2[i]));
}
