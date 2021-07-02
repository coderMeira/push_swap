#include "push_swap.h"

t_stack_elem	*find_a_elem(t_stack *a_stack, int	index)
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
}

static void	calculate_directions(t_stack *stack, int index, t_sizes *xsize)
{
	t_stack_elem	*current;

	if (stack && stack->head)
	{
		current = stack->head;
		while (current->index != index)
		{
			(xsize->rx)++;
			current = current->next;
		}
		current = stack->head;
		while (current->index != index)
		{
			(xsize->rrx)++;
			current = current->previous;
		}
	}
}

static void	set_direction(size_t size,
				t_shift_info new_shift_info,
				t_shift_info *shift_info)
{
	if (!shift_info->is_set || size < shift_info->size)
	{
		shift_info->a_elem = new_shift_info.a_elem;
		shift_info->b_elem = new_shift_info.b_elem;
		shift_info->a_direction = new_shift_info.a_direction;
		shift_info->b_direction = new_shift_info.b_direction;
		shift_info->size = size;
		shift_info->is_set = true;
	}
}

static size_t	find_min(t_sizes *x)
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

static size_t	decide_directions(t_sizes *a, t_sizes *b, t_shift_info *shift)
{
	size_t	min_a;
	size_t	min_b;
	size_t	lowest;

	min_a = find_min(a);
	min_b = find_min(b);
	lowest = min_a + min_b;
	shift->a_direction = a->direction;
	shift->b_direction = b->direction;
	if (a->rx == b->rx && (((a->rx + b->rx) / 2) <= lowest))
	{
		shift->a_direction = R;
		shift->b_direction = R;
		lowest = ((a->rx + b->rx) / 2);
	}
	if (a->rrx == b->rrx && (((a->rrx + b->rrx) / 2) <= lowest))
	{
		shift->a_direction = RR;
		shift->b_direction = RR;
		lowest = ((a->rrx + b->rrx) / 2);
	}
	return (lowest);
}

void	optimal_direction(t_stack *a_stack, t_stack *b_stack,
							t_stack_elem *b_elem, t_shift_info *shift_info)
{
	t_shift_info	new_shift_info;
	size_t			size;
	t_sizes			*new_a;
	t_sizes			*new_b;

	new_a = init_r_struct();
	new_b = init_r_struct();
	new_shift_info.a_elem = find_a_elem(a_stack, b_elem->index);
	new_shift_info.b_elem = b_elem;
	calculate_directions(a_stack, new_shift_info.a_elem->index, new_a);
	calculate_directions(b_stack, b_elem->index, new_b);
	size = decide_directions(new_a, new_b, &new_shift_info);
	set_direction(size, new_shift_info, shift_info);
	free(new_a);
	free(new_b);
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
