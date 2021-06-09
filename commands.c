
#include "push_swap.h"

t_command		*create_command(const char *name)
{
	t_command *command;

	command	= (t_command *)malloc(sizeof(t_command));
	if (!command)
		terminate();
	command->name = ft_strdup(name));
	if (!command->name)
		terminate();
	command->next = NULL;
	return (command);
}

void			add_command(t_command_list *list,
					t_command *command)
{
	t_command *last;

	if (list && command)
	{
		if (!list->head)
			list->head = command;
		else
		{
			last = list->head;
			while (last->next)
				last = last->next;
			last->next = command;
		}
	}
}
