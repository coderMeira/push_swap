/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:31:55 by fmeira            #+#    #+#             */
/*   Updated: 2021/07/06 19:31:55 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	terminate(void)
{
	ft_putendl_fd("Error\n", 2);
	exit(1);
}

int	main(int ac, char**av)
{
	t_stack			*stack_a;
	t_command_list	*commands;

	if (ac >= 2)
	{
		stack_a = parse(ac, av);
		index_stack(stack_a);
		markup(stack_a);
		commands = solve(stack_a);
		free_stack(stack_a);
		print_commands(commands);
		free_command_list(commands);
	}
	else
		terminate();
	return (0);
}
