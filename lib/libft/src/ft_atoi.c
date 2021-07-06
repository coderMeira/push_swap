/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:52:23 by fmeira            #+#    #+#             */
/*   Updated: 2021/07/06 20:04:59 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	stuff(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f' || c == '+')
		return (true);
	return (false);
}

int	ft_atoi(const char *str)
{
	int		signal;
	int		result;
	char	*p;

	p = (char *)str;
	signal = 1;
	result = 0;
	while (stuff(*p))
		p++;
	if (*p == '-')
	{
		p++;
		signal = -1;
	}
	while (*p > 47 && *p < 58)
	{
		result = result * 10 + *p - 48;
		p++;
		if (result * signal < -2147483648)
			return (0);
	}
	return (result * signal);
}
