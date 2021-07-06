#include "push_swap.h"

t_stack_elem	*create_elem(int number)
{
	t_stack_elem	*new;

	new = (t_stack_elem *)malloc(sizeof(t_stack_elem));
	if (!new)
		terminate();
	new->number = number;
	new->index = 0;
	new->keep_in_stack = false;
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

void	add(t_stack *stack, t_stack_elem *elem)
{
	t_stack_elem	*tail;

	if (stack && elem)
	{
		if (!stack->head)
		{
			stack->head = elem;
			stack->head->next = stack->head;
			stack->head->previous = stack->head;
		}
		else
		{
			tail = stack->head->previous;
			elem->previous = tail;
			tail->next = elem;
			elem->next = stack->head;
			stack->head->previous = elem;
		}
		stack->size++;
	}
}
