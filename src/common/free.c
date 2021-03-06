#include <stdlib.h>
#include "../../inc/push_swap.h"

void	free_command_list(t_command_list *list)
{
	t_command	*current;
	t_command	*delete;

	current = list->head;
	while (current)
	{
		delete = current;
		current = current->next;
		free(delete->name);
		free(delete);
	}
	free(list);
}

void	free_stack(t_stack *stack)
{
	size_t			i;
	t_stack_elem	*current;
	t_stack_elem	*delete;

	i = 0;
	current = stack->head;
	while (i < stack->size)
	{
		delete = current;
		current = current->next;
		free(delete);
		i++;
	}
	free(stack);
}
