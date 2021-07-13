#include "../../inc/push_swap.h" 

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		terminate();
	stack->head = NULL;
	stack->size = 0;
	stack->pairs = 0;
	stack->markup_head = NULL;
	return (stack);
}

t_shift_info	*init_shift_info(void)
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

t_sizes	*init_r_struct(void)
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
