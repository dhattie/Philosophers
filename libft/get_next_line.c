/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:02:25 by dhattie           #+#    #+#             */
/*   Updated: 2021/05/24 21:02:30 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_bags(int push_to_line, int sub_line, int byte_read, char **rem)
{
	if (!push_to_line || !sub_line)
		return (-1);
	if (byte_read == 0 && **rem == '\0')
	{
		free(*rem);
		*rem = NULL;
		return (0);
	}
	return (1);
}

int	sub_line(char **rem)
{
	char	*index;
	char	*tmp;

	index = ft_strchr(*rem, '\n');
	if (index)
		index++;
	tmp = *rem;
	if (!index)
		*rem = ft_strdup("");
	else
		*rem = ft_strdup(index);
	free(tmp);
	tmp = NULL;
	if (*rem)
		return (1);
	else
		return (0);
}

int	push_to_line(char **rem, char **line)
{
	char	*index;

	index = ft_strchr(*rem, '\n');
	if (index)
		*index = '\0';
	*line = ft_strdup(*rem);
	if (index)
		*index = '\n';
	if (!*line)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		bf[BUFFER_SIZE + 1];
	char static	*rem = NULL;
	char		*tmp;
	size_t		byte_read;
	int			bag;

	byte_read = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (-1);
	if (!rem)
		rem = ft_strdup("");
	while (rem && !ft_strchr(rem, '\n') && byte_read)
	{
		byte_read = read(fd, bf, BUFFER_SIZE);
		bf[byte_read] = '\0';
		tmp = rem;
		rem = ft_strjoin(rem, bf);
		if (tmp)
			free(tmp);
	}
	bag = check_bags(push_to_line(&rem, line), sub_line(&rem), byte_read, &rem);
	return (bag);
}
