#include "push_swap.h"

static void			move_b(t_stack *a_stack,
						t_stack *b_stack,
						t_shift_info *shift_info,
						t_command_list *command_list)
{
	while (shift_info->a_elem != a_stack->head
		|| shift_info->b_elem != b_stack->head)
	{
		if (shift_info->a_direction == shift_info->b_direction
			&& shift_info->a_elem != a_stack->head
			&& shift_info->b_elem != b_stack->head)
		{
			if (shift_info->a_direction == R)
				rr(a_stack, b_stack, "rr", command_list);
			else
				rrr(a_stack, b_stack, "rrr", command_list);
		}
		else if (shift_info->a_elem != a_stack->head)
		{
			if (shift_info->a_direction == R)
				rx(a_stack, "ra", command_list);
			else
				rrx(a_stack, "rra", command_list);
		}
		else if (shift_info->b_elem != b_stack->head)
		{
			if (shift_info->b_direction == R)
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
