#include "../../inc/push_swap.h"

static void	swap(t_stack_elem *first, t_stack_elem *second, t_stack *stack)
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

void	sx(t_stack *stack, char *name, t_command_list *list)
{
	if (stack && stack->head && stack->size >= 2)
		swap(stack->head, stack->head->next, stack);
	if (name && !list)
		ft_putendl(name);
	if (name && list)
		add_command(list, create_command(name));
}

void	ss(t_stack *a, t_stack *b, const char *name, t_command_list *list)
{
	sx(a, NULL, NULL);
	sx(b, NULL, NULL);
	if (name && !list)
		ft_putendl(name);
	if (name && list)
		add_command(list, create_command(name));
}
