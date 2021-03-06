#include "../../inc/push_swap.h"  

static void	align_a(t_stack *a_stack,
					t_command_list *command_list)
{
	t_stack_elem	*current;
	size_t			ra_size;
	size_t			rra_size;

	if (a_stack && a_stack->head)
	{
		ra_size = 0;
		current = a_stack->head;
		while (current->index != 0)
		{
			ra_size++;
			current = current->next;
		}
		rra_size = 0;
		current = a_stack->head;
		while (current->index != 0)
		{
			rra_size++;
			current = current->previous;
		}
		while (a_stack->head->index != 0 && (ra_size < rra_size))
			rx(a_stack, "ra", command_list);
		while (a_stack->head->index != 0 && !(ra_size < rra_size))
			rrx(a_stack, "rra", command_list);
	}
}

t_command_list	*solve(t_stack	*a_stack)
{
	t_command_list	*command_list;
	t_stack			*b_stack;

	command_list = init_command_list();
	b_stack = init_stack();
	solve_a(a_stack, b_stack, command_list);
	solve_b(a_stack, b_stack, command_list);
	align_a(a_stack, command_list);
	free_stack(b_stack);
	return (command_list);
}
