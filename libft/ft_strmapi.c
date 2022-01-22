/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:47:54 by dhattie           #+#    #+#             */
/*   Updated: 2021/05/03 19:47:57 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Applies the function f to each character of the string passed as argument to
 create a new string (with malloc) resulting from successive applications of f
 */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f (i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
