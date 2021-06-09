
#include "push_swap.h";

t_command_list	*solve(t_stack	*a_stack)
{
	t_command_list	*command_list;
	t_stack			*b_stack;

	command_list = init_command_list();
	b_stack = init_stack();

	solve_a(a_stack, b_stack, command_list);
	// solve_b(a_stack, b_stack, command_list);
	// rearrange(a_stack, command_list);
	// free_stack(b_stack);
	return (command_list);
}
