/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:30:23 by fmeira            #+#    #+#             */
/*   Updated: 2021/07/03 19:54:44 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	alloc;
	char	*p;

	alloc = size * count;
	p = malloc(alloc);
	if (!(p))
		return (NULL);
	ft_bzero(p, alloc);
	return (p);
}
