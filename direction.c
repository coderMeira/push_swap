#include "push_swap.h"

//find a_elem
//calcular rx/rrx do a/b para head
//se o new_rb_size for maior que o ultimo. actualizar shift info e rb
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
}

static void			calculate_size(t_stack *stack,
						int index,
						size_t **rx_size,
						size_t **rrx_size)
{
	t_stack_elem	*current;
	t_stack			*stacky;

	stacky = stack;
	printf("ola\n");
	if (stack && stack->head)
	{
		current = stacky->head;
		while (current->index != index)
		{
			(*rx_size)++;
			current = current->next;
		}
		current = stacky->head;
		while (current->index != index)
		{
			(*rrx_size)++;
			current = current->previous;
		}
	}

}

static void			estimate_direction(t_stack *stack,
						int index,
						size_t *rx_size,
						size_t *rrx_size)
{
	size_t			*new_rx;
	size_t			*new_rrx;
	static t_bool	is_set;

	*new_rx = 0;
	*new_rrx = 0;
	is_set = false;

	if (is_set == false)
	{
		calculate_size(stack, index, &rx_size, &rrx_size);
		is_set = true;
	}
	else
		calculate_size(stack, index, &new_rx, &new_rrx);
	if (((*new_rx) < (*rx_size)) && is_set == true)
		*rx_size = *new_rx;
	if (((*new_rrx) < (*rrx_size)) && is_set == true)
		 *rrx_size = *new_rrx;
}

static void			set_direction(size_t size,
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

void optimal_direction(t_stack *a_stack, t_stack *b_stack,
    				  t_stack_elem *b_elem, t_shift_info *shift_info)
{
	t_shift_info		current_shift_info;
	static size_t		rb_size;
	static size_t		ra_size;
	static size_t		rrb_size;
	static size_t		rra_size;


	rb_size = 0;
	ra_size = 0;
	rrb_size = 0;
	rra_size = 0;
	current_shift_info.a_elem = find_a_elem(a_stack, b_elem->index);
	current_shift_info.b_elem = b_elem;


	estimate_direction(a_stack, current_shift_info.a_elem->index, &ra_size,
					   &rra_size);
	estimate_direction(b_stack, b_elem->index, &rb_size, &rrb_size);
	printf("rb size for %d = %ld\n", b_elem->number, rb_size);
	printf("rrb size for %d = %ld\n", b_elem->number, rrb_size);
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
		//printf("a size %zu\n", a_stack->size);
		//printf("a head %d\n", a_stack->head->number);
		while (i < b_stack->size)
		{
			optimal_direction(a_stack, b_stack, current, shift_info);
			i++;
			current = current->next;
		}
	}
}
