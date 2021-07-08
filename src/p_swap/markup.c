#include "../../inc/push_swap.h"

size_t	markup_stack(t_stack *stack, t_stack_elem *markup_head)
{
	ssize_t			index;
	size_t			pairs;
	t_stack_elem	*current;

	pairs = 0;
	if (stack && markup_head)
	{
		index = markup_head->index;
		markup_head->keep_in_stack = true;
		current = markup_head->next;
		while (current != markup_head)
		{
			if (current->index > index)
			{
				pairs++;
				index = current->index;
				current->keep_in_stack = true;
			}
			else
				current->keep_in_stack = false;
			current = current->next;
		}
	}
	return (pairs);
}

void	markup(t_stack	*stack)
{
	size_t			i;
	t_stack_elem	*current;
	size_t			pairs;

	i = 0;
	current = stack->head;
	if (stack)
	{
		while (i < stack->size)
		{
			pairs = markup_stack(stack, current);
			if (pairs > stack->pairs)
			{
				stack->markup_head = current;
				stack->pairs = pairs;
			}
			else if (pairs == stack->pairs && (!stack->markup_head
					|| current->number < stack->markup_head->number))
				stack->markup_head = current;
			i++;
			current = current->next;
		}
	}
	markup_stack(stack, stack->markup_head);
}
