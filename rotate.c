
#include "push_swap.h"

void	rx(t_stack *stack,
			const char *name,
			t_command_list *list)
{
	if (stack && stack->head)
		stack->head = stack->head->next;
	if (name && !list)
		ft_putendl(name);
	if (name && list)
		add_command(list, create_command(name));
}

void	rr(t_stack *a,
			t_stack *b,
			const char *name,
			t_command_list *list)
{
	rx(a, NULL, NULL);
	rx(b, NULL, NULL);
	if (name && !list)
		ft_putendl(name);
	if (name && list)
		add_command(list, create_command(name));
}
