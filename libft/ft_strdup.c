/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:43:23 by dhattie           #+#    #+#             */
/*   Updated: 2021/05/03 19:43:58 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strdup () function returns a pointer to a new
string that is a duplicate of s. The memory for the
newline is allocated with malloc and can be freed with free.
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*copy;

	len = ft_strlen(src);
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
