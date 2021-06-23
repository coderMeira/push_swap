#include "push_swap.h"

//find a_elem
//calcular rx/rrx do a/b para head
//actualizar shift_info com a soma minima de ra/rra + rb/rrb

t_stack_elem *find_a_elem(t_stack *a_stack, ssize_t	index)
{
	t_stack_elem	*current;

	current = a_stack->markup_head;
	if (index < current->index)
	{
		while (index < current->previous->index
			&& current->index > current->previous->index)
			current = current->previous;
	}
	else
	{
		while (index > current->index
			&& current->index < current->next->index)
			current = current->next;
		if (index > current->index && current->index > current->next->index)
			current = current->next;
	}
	return (current);
	// t_stack_elem	*current;
	// size_t			i;

	// current = a_stack->head;
	// i = 0;
	// while (i < a_stack->size)
	// {
	// 	if (b_index == (current->index - 1))
	// 		return (current);
	// 	current = current->next;
	// 	i++;
	// }
	// return (current);
}

void optimal_direction(t_stack *a_stack, t_stack *b_stack,
    				  t_stack_elem *b_elem, t_shift_info *shift_info)
{
	t_shift_info	current_shift_info;
	int				rb_size;
	int				ra_size;
	int				rrb_size;
	int				rra_size;

	rb_size = 0;
	ra_size = 0;
	rrb_size = 0;
	rra_size = 0;
	current_shift_info.a_elem = find_a_elem(a_stack, b_elem->index);
	printf("a_elem for %d = %d\n", b_elem->number, current_shift_info.a_elem->number);
}

void opt_direction(t_stack *a_stack, t_stack *b_stack, t_shift_info *shift_info)
{
	t_stack_elem	*current;
	size_t			i;

	if (b_stack)
	{
		current = b_stack->head;
		i = 0;
		ft_print_stacks(a_stack, b_stack);
		printf("a size %zu\n", a_stack->size);
		printf("a head %d\n", a_stack->head->number);
		while (i < b_stack->size)
		{
			optimal_direction(a_stack, b_stack, current, shift_info);
			i++;
			current = current->next;
		}
	}
}
