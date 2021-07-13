#include "../../inc/push_swap.h"
#include "../../inc/get_next_line.h"

static t_bool	is(char *command, char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] != command[i])
			return (false);
		i++;
	}
	return (true);
}

static void	execute_instruction(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (is("sa", line))
		sx(stack_a, "sa", NULL);
	else if (is("sb", line))
		sx(stack_b, "sb", NULL);
	else if (is("ss", line))
		ss(stack_a, stack_b, "ss", NULL);
	else if (is("ra", line))
		rx(stack_a, "ra", NULL);
	else if (is("rb", line))
		rx(stack_b, "rb", NULL);
	else if (is("rr", line))
		rr(stack_a, stack_b, "rr", NULL);
	else if (is("pa", line))
		px(stack_a, stack_b, "pa", NULL);
	else if (is("pb", line))
		px(stack_b, stack_a, "pb", NULL);
	else if (is("rra", line))
		rrx(stack_a, "rra", NULL);
	else if (is("rrb", line))
		rrx(stack_b, "rrb", NULL);
	else if (is("rrr", line))
		rrr(stack_a, stack_b, "rrr", NULL);
	else
		terminate();
}

t_bool	evaluate(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_elem	*current;
	t_stack_elem	*previous;

	current = stack_a->head->next;
	previous = stack_a->head;
	if (stack_b->head)
		return (false);
	while (current != stack_a->head)
	{
		if (current->number < previous->number)
			return (false);
		previous = current;
		current = current->next;
	}
	return (true);
}

static void	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = (char *)malloc(4 * sizeof(char));
	if (!line)
		return ;
	while (get_next_line(0, &line) > 0)
		execute_instruction(stack_a, stack_b, line);
	if (evaluate(stack_a, stack_b))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	free(line);
}

int	main(int ac, char **av)
{
	t_stack			*stack_a;
	t_stack			*stack_b;

	stack_b = init_stack();
	if (ac >= 2)
	{
		stack_a = parse(ac, av);
		checker(stack_a, stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	return (0);
}
