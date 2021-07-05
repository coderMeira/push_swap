#include "push_swap.h"

void	index_stack(t_stack *stack)
{
	ssize_t			i;
	ssize_t			j;
	t_stack_elem	*currentIndex;
	t_stack_elem	*currentJ;

	i = 0;
	currentIndex = stack->head;
	currentJ = currentIndex;
	if (stack)
	{
		while (i < stack->size)
		{
			j = 0;
			while (j < stack->size)
			{
				if (currentJ->number < currentIndex->number)
					currentIndex->index++;
				currentJ = currentJ->next;
				j++;
			}
			currentIndex = currentIndex->next;
			currentJ = stack->head;
			i++;
		}
	}
}

t_bool	has_duplicates(t_stack *stack)
{
	size_t			i;
	t_stack_elem	*current_i;
	t_stack_elem	*current_j;

	i = 0;
	current_i = stack->head;
	if (stack)
	{
		while (i < stack->size)
		{
			current_j = current_i->next;
			while (current_j != current_i)
			{
				if (current_j->number == current_i->number)
					return (true);
				current_j = current_j->next;
			}
			current_i = current_i->next;
			i++;
		}
	}
	return (false);
}

t_bool	not_int(char *s)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = ft_strlen(s);
	tmp = s;
	if (ft_stoi(tmp) > 2147483647)
		return (false);
	if (s[i] == '-' && ft_isdigit(s[1]))
		i++;
	while (i < len)
	{
		if (!(ft_isdigit(s[i++])))
			return (true);
	}
	return (false);
}

t_stack	*parse(int ac, char **av)
{
	int		i;
	t_stack	*stack;

	i = 1;
	stack = init_stack();
	while (i < ac)
	{
		if (not_int(av[i]))
			terminate();
		add(stack, create_elem(ft_stoi(av[i++])));
	}
	if (!(stack->size) || has_duplicates(stack))
		terminate();
	return (stack);
}
