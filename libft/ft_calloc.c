/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:30:23 by fmeira            #+#    #+#             */
/*   Updated: 2021/02/24 15:39:56 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	alloc;
	char	*p;

	alloc = size * count;
	if (!(p = malloc(alloc)))
		return (NULL);
	ft_bzero(p, alloc);
	return (p);
}
