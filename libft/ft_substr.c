/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 10:58:04 by dhattie           #+#    #+#             */
/*   Updated: 2021/04/25 10:58:06 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc), returns a substring from the string given in argument.
The substring begins at index 'start' and is of maximum size 'len'
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	int			s_len;
	int			i;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen((char *)s);
	if ((int)start >= s_len)
		return (ft_strdup(""));
	if (s_len < (int)len)
		len = s_len - i;
	else
		len = len - i;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < (int)len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
