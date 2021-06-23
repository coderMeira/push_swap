#include "push_swap.h"

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
	return (shift_info);
}

void	solve_b(t_stack	*a_stack, t_stack *b_stack,
				t_command_list	*command_list)
{
	t_shift_info	*shift_info;

	shift_info = init_shift_info();
	opt_direction(a_stack, b_stack, shift_info);

	// while (b_stack->size)
	// {
	// 	shift_info->is_set = false;
	// 	opt_direction(a_stack, b_stack, shift_info);
	// 	//move_b(a_stack, b_stack, shift_info, command_list);
	// 	//px(a_stack, b_stack, "pa", command_list);
	// }
	free(shift_info);
}