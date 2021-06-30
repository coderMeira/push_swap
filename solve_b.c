#include "push_swap.h"

static	t_sizes	*init_r_struct(void)
{
	t_sizes		*new;

	new = (t_sizes *)malloc(sizeof(t_sizes));
	if (!new)
		terminate();

	new->rx = 0;
	new->rrx = 0;
	new->direction = R;

	return (new);
}

static t_shift_info	*init_shift_info(void)
{
	t_shift_info	*shift_info;


	shift_info = (t_shift_info *)malloc(sizeof(t_shift_info));
	if (!shift_info)
		terminate();
	shift_info->a_elem = NULL;
	shift_info->b_elem = NULL;
	shift_info->a_direction = R;
	shift_info->b_direction = R;
	shift_info->size = 0;
	shift_info->is_set = false;
}

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
			if (shift_info->a_direction == R)
				rr(a_stack, b_stack, "rr", command_list);
			else
				rrr(a_stack, b_stack, "rrr", command_list);
		else if (shift_info->a_elem != a_stack->head)
			if (shift_info->a_direction == R)
				rx(a_stack, "ra", command_list);
			else
				rrx(a_stack, "rra", command_list);
		else if (shift_info->b_elem != b_stack->head)
			if (shift_info->b_direction == R)
				rx(b_stack, "rb", command_list);
			else
				rrx(b_stack, "rrb", command_list);
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
