
#include "push_swap.h"

void	px(t_stack	*to, t_stack *from, const char *name, t_command_list *list)
{
	push(to, pop(from));
	// if (name && !list)
	// 	ft_putendl_fd(name, 1);
	if (name && list)
		add_command(list, create_command(name));
}

void		push(t_stack *stack, t_stack_elem *popped)
{
	t_stack_elem	*tail;

	if (stack && popped)
	{
		if (!stack->head)
		{
			stack->head = popped;
			stack->head->next = stack->head;
			stack->head->previous = stack->head;
		}
		else
		{
			tail = stack->head->previous;
			popped->previous = tail;
			tail->next = popped;
			popped->next = stack->head;
			stack->head->previous = popped;
			stack->head = popped;
		}
		stack->size++;
	}
}


t_stack_elem *pop(t_stack *stack)
{
	t_stack_elem *elem;

	elem = NULL;
	if (stack && stack->size)
	{
		if (stack->size == 1)
		{
			elem = stack->head;
			stack->head = NULL;
			elem->next = NULL;
			elem->previous = NULL;
		}
		else
		{
			elem = stack->head;
			stack->head = elem->next;
			elem->previous->next = elem->next;
			stack->head->previous = elem->previous;
			elem->next = NULL;
			elem->previous = NULL;
		}
		stack->size--;
	}
	return (elem);
}
