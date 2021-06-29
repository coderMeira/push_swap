#include "push_swap.h"

//find a_elem
//calcular rx/rrx do a/b para head
//se o new_rb_size for maior que o ultimo. actualizar shift info e rb
//actualizar shift_info com a soma minima de ra/rra + rb/rrb
//(free sizes);

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

t_stack_elem *find_a_elem(t_stack *a_stack, int	index)
{
	t_stack_elem	*current;

	current = a_stack->markup_head;
	//printf("markup head = %d\n", current->index);
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
	//printf("last index = %d\n", current->index);

	}
	return (current);
}

static void			calculate_directions(t_stack *stack, int index, t_sizes *xsize)
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
static size_t	find_min(t_sizes *x)
{
	if (x->rrx > x->rx)
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

	min_a = find_min(a);
	min_b = find_min(b);
	if (a->rx == b->rx || a->rrx == b->rrx)
	{
		if ((((a->rx + b->rx) / 2) <= min_a) && (((a->rx + b->rx) / 2) <= min_b))
		{
			shift->a_direction = R;
			shift->b_direction = R;
			return (a->rx + b->rx / 2);
		}
		else if ((((a->rrx + b->rrx) / 2) <= min_a) && (((a->rrx + b->rrx) / 2) <= min_b))
		{
			shift->a_direction = RR;
			shift->b_direction = RR;
			return (a->rrx + b->rrx / 2);
		}
	}
	else
	{
		shift->a_direction = a->direction;
		shift->b_direction = b->direction;
		return (min_a + min_b);
	}
}

void optimal_direction(t_stack *a_stack, t_stack *b_stack,
    				  t_stack_elem *b_elem, t_shift_info *shift_info)
{
	t_shift_info	new_shift_info;
	size_t			size;
	t_sizes			new_a;
	t_sizes			new_b;

	new_shift_info.a_elem = find_a_elem(a_stack, b_elem->index);
	new_shift_info.b_elem = b_elem;
	calculate_directions(a_stack, new_shift_info.a_elem->index, &new_a);
	calculate_directions(b_stack, b_elem->index, &new_b);
	size = decide_directions(&new_a, &new_b, &new_shift_info);
	printf("a direction for %d = %d\n",new_shift_info.a_elem->number, new_shift_info.a_direction);
	printf("b direction for %d = %d\n",b_elem->number, new_shift_info.b_direction);
	set_direction(size, new_shift_info, shift_info);

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
			printf("current best elements = A:%d B:%d\n", shift_info->a_elem->number, shift_info->b_elem->number);
			printf("current best a direction = %d\n", shift_info->a_direction);
			printf("current best b direction = %d\n", shift_info->b_direction);
			printf("-------------------------------------------------------\n");
		}
	}
}
