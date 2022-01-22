/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:46:31 by dhattie           #+#    #+#             */
/*   Updated: 2021/05/03 19:46:34 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	kol_no_c_in_mas(const char *str, char c)
{
	int	kol;
	int	i;

	if (!str || !c)
		return (0);
	i = 0;
	kol = 0;
	while (str[i])
	{
		if (str[i] != c)
			kol++;
		else
			return (kol);
		i++;
	}
	return (kol);
}

int	kol_substr_in_mass(const char *str, char c)
{
	int	kol_c;
	int	i;

	if (!str || !c)
		return (0);
	i = 0;
	kol_c = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			kol_c++;
		while (str[i] != c && str[i])
			i++;
	}
	return (kol_c);
}

char	**ft_split(const char *str, char c)
{
	char	**mas;
	int		i;
	int		j;
	int		t;

	mas = malloc(sizeof (char *) * (kol_substr_in_mass(str, c) + 1));
	if (!mas || !str)
		return (NULL);
	i = 0;
	t = 0;
	while (t <= ft_strlen(str) && str[t] != 0)
	{
		j = 0;
		while (str[t] == c)
			t++;
		if (!str[t])
			break ;
		mas[i] = malloc(sizeof(char) * (kol_no_c_in_mas(&str[t], c) + 1));
		while (str[t] != c && str[t])
			mas[i][j++] = str[t++];
		mas[i++][j] = '\0';
		t++;
	}
	mas[i] = NULL;
	return (mas);
}
