#include "../../inc/push_swap.h"

static void	move_b(t_stack *a_stack,
					t_stack *b_stack,
					t_shift_info *s,
					t_command_list *command_list)
{
	while (s->a_elem != a_stack->head || s->b_elem != b_stack->head)
	{
		if (s->a_direction == s->b_direction && s->a_elem != a_stack->head
			&& s->b_elem != b_stack->head)
		{
			if (s->a_direction == R)
				rr(a_stack, b_stack, "rr", command_list);
			else
				rrr(a_stack, b_stack, "rrr", command_list);
		}
		else if (s->a_elem != a_stack->head)
		{
			if (s->a_direction == R)
				rx(a_stack, "ra", command_list);
			else
				rrx(a_stack, "rra", command_list);
		}
		else if (s->b_elem != b_stack->head)
		{
			if (s->b_direction == R)
				rx(b_stack, "rb", command_list);
			else
				rrx(b_stack, "rrb", command_list);
		}
	}
}

void	solve_b(t_stack	*a_stack, t_stack *b_stack,
				t_command_list	*command_list)
{
	t_shift_info	*shift_info;

	shift_info = init_shift_info();
	while (b_stack->size)
	{
		shift_info->is_set = false;
		opt_direction(a_stack, b_stack, shift_info);
		move_b(a_stack, b_stack, shift_info, command_list);
		px(a_stack, b_stack, "pa", command_list);
	}
	free(shift_info);
}

size_t	find_min(t_sizes *x)
{
	if (x->rx < x->rrx)
	{
		x->direction = R;
		return (x->rx);
	}
	else
	{
		x->direction = RR;
		return (x->rrx);
	}
}

void	opt_direction(t_stack *a_stack, t_stack *b_stack,
						t_shift_info *shift_info)
{
	t_stack_elem	*current;
	size_t			i;

	if (b_stack)
	{
		current = b_stack->head;
		i = 0;
		while (i < b_stack->size)
		{
			optimal_direction(a_stack, b_stack, current, shift_info);
			i++;
			current = current->next;
		}
	}
}
