#include "push_swap.h"

//find a_elem
//calcular rx/rrx do a/b para head
//se o new_rb_size for maior que o ultimo. actualizar shift info e rb
//actualizar shift_info com a soma minima de ra/rra + rb/rrb
//(free sizes);


t_stack_elem *find_a_elem(t_stack *a_stack, int	index)
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

static void			calculate_size(t_stack *stack, int index, t_sizes *xsize)
{
	t_stack_elem	*current;

	if (stack && stack->head)
	{
		current = stack->head;
		printf("ola 1.9\n");
		while (current->index != index)
		{
			printf("index = %d\n", index);
			printf("ra = %ld\n", xsize->rx);
			printf("current = %ld\n", current->index);
			(xsize->rx)++;
			current = current->next;
		}
		printf("ola 2\n");
		current = stack->head;
		while (current->index != index)
		{
			(xsize->rrx)++;
			current = current->previous;
		}
	}
}

static void			estimate_direction(t_stack *stack, int index, t_sizes *xsize)
{
	t_sizes *current;

	current->rx = 0;
	current->rrx = 0;

	printf("INDEX ----- %d\n", index);
	printf("ola 1\n");
	if (!(xsize->r_is_set))
	{
		printf("ola 1.8\n");
		//calculate_size(stack, index, xsize);
		xsize->r_is_set = true;
	}
	else
		//calculate_size(stack, index, current);
	printf("ola 3\n");
	if ((current->rx < xsize->rx) && xsize->r_is_set == true)
		xsize->rx = current->rx;
	if ((current->rrx < xsize->rrx) && xsize->r_is_set == true)
		xsize->rrx = current->rrx;
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
	t_shift_info	current_shift_info;


	current_shift_info.a_elem = find_a_elem(a_stack, b_elem->index);
	current_shift_info.b_elem = b_elem;
	estimate_direction(a_stack, current_shift_info.a_elem->index,
						shift_info->lowest_r_a);
	estimate_direction(b_stack, b_elem->index, shift_info->lowest_r_b);
	printf("rb size for %d = %ld\n", b_elem->number, shift_info->lowest_r_b->rx);
	printf("rrb size for %d = %ld\n", b_elem->number, shift_info->lowest_r_b->rrx);
	printf("a_elem for %d = %d\n", b_elem->number, current_shift_info.a_elem->number);
	printf("---------------------------------------------------------------\n");
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
