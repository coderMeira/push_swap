/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:31:55 by fmeira            #+#    #+#             */
/*   Updated: 2021/06/02 18:47:02 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_print_stack(t_stack *stack)
{
	int	i;
	t_stack_elem *current;

	i = 0;
	current = stack->head;
	while (i++ < stack->size)
	{
		printf("nbr: %d", current->number);
		if (current->number > 9)
			printf(" | ");
		else
			printf("  | ");
		printf("index: %zd", current->index);
		if (current->index > 9)
			printf(" | ");
		else
			printf("  | ");
		printf("keep in stack: %u", current->keep_in_stack);
		if (current == stack->markup_head)
			printf(" <---- markup | pairs: %zd", stack->pairs);
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
	t_command_list	commands;

	if (ac >= 2)
	{
		index_stack(stack_a = parse(ac, av));
		markup_stack(stack_a);
		commands = solve(stack_a);
		ft_print_stack(stack_a);
	}
	else
		;
	return (0);
}
