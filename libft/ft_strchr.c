/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 20:56:36 by dhattie           #+#    #+#             */
/*   Updated: 2021/04/28 20:56:38 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Locates the first occurrence of 'c' in the string pointed to by 's'. 
The terminating null character is considered to be part of the string, 
therefore if 'c' is '\0', locates the terminating '\0'
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
