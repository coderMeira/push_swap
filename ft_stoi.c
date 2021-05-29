/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:08:06 by fmeira            #+#    #+#             */
/*   Updated: 2021/05/28 17:02:04 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stoi(char *str)
{
	int		signal;
	int		result;
	char	*p;

	p = (char *)str;
	signal = 1;
	result = 0;
	while (*p == ' ' || *p == '\t' || *p == '\n'
		|| *p == '\r' || *p == '\v' || *p == '\f')
		p++;
	if (*p == '+')
		p++;
	else if (*p == '-')
	{
		p++;
		signal = -1;
	}
	while (*p > 47 && *p < 58)
	{
		result = result * 10 + *p++ - 48;
		if (result * signal < -2147483648)
			return (0);
	}
	return (result * signal);
}
