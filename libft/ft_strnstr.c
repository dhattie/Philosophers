/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:01:15 by dhattie           #+#    #+#             */
/*   Updated: 2021/04/29 21:01:17 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Finds the first occurrence of the substring 'needle' in the string 'haystack'
*/

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		j = 0;
		if (hay[i] == needle[0])
		{
			while ((hay[i + j] == needle[j]) && (i + j < len))
			{
				if (needle[j + 1] == '\0')
					return ((char *)&hay[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
