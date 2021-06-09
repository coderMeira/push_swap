
#include "push_swap.h"

static void swap(t_stack_elem *first, t_stack_elem *second, t_stack *stack)
{
	t_stack_elem	*previous;
	t_stack_elem	*next;

	previous = first->previous;
	next = second->next;
	previous->next = second;
	second->previous = previous;
	second->next = first;
	next->previous = first;
	first->next = next;
	first->previous = second;
	stack->head = second;
}

void sx(t_stack *stack, char *arg, t_command_list *list)
{
	if (stack && stack->head && stack->size >= 2)
		swap(stack->head, stack->head->next, stack);
	if (arg && !list)
		ft_putendl(arg);
	if (arg && list)
		add_command(list, create_command(arg));
}
