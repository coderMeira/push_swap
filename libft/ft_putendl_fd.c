/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:06:12 by fmeira            #+#    #+#             */
/*   Updated: 2021/07/03 20:09:48 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	nl;
	char	*n;

	nl = '\n';
	n = &nl;
	if (!s || fd < 0)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, n, 1);
}
