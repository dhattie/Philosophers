/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:42:34 by dhattie           #+#    #+#             */
/*   Updated: 2021/05/03 19:42:38 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
calloc () allocates memory for an nmemb array,
each element of which is size bytes, and returns
a pointer to the allocated memory.
*/

#include "libft.h"

void	*ft_calloc(size_t array, size_t size)
{
	void	*addr;

	addr = malloc(array * size);
	if (addr)
		ft_memset(addr, 0, array * size);
	return (addr);
}
