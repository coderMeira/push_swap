/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:31:55 by fmeira            #+#    #+#             */
/*   Updated: 2021/06/30 20:13:06 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int			 i;
	t_stack_elem *current;

	i = 0;
	current = stack_a->head;
	printf(" A\n");
	while (i++ < stack_a->size)
	{
		printf("|");
		printf("%d", current->number);
		if (current->number > 9)
			printf("| ");
		else
			printf(" | ");
		printf("\n");
		current = current->next;
	}
	i = 0;
	current = stack_b->head;
	printf("\n B\n");
	while (i++ < stack_b->size)
	{
		printf("|");
		printf("%d", current->number);
		if (current->number > 9)
			printf("| ");
		else
			printf(" | ");
		printf("\n");
		current = current->next;
	}
}

void	terminate()
{
    ft_putendl_fd("Error", 2);
    exit(1);
}

int main(int ac, char** av)
{
	t_stack			*stack_a;
	t_command_list	*commands;

	if (ac >= 2)
	{
		index_stack(stack_a = parse(ac, av));
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
