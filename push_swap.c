/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:31:55 by fmeira            #+#    #+#             */
/*   Updated: 2021/05/31 22:17:25 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void ft_print_stack(t_stack *stack)
{
	int	i;
	t_stack_elem *current;

	i = 0;
	current = stack->head;
	while (i++ < stack->size)
	{
		printf("nbr: %d------", current->number);
		printf("index: %zd\n", current->index);
		current = current->next;
	}
}

int main(int ac, char** av)
{
	t_stack		*stack_a;

	if (ac >= 2)
	{
		index_stack(stack_a = parse(ac, av));
		ft_print_stack(stack_a);
	}
	else
		;
	return (0);
}
