/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:11:29 by fmeira            #+#    #+#             */
/*   Updated: 2021/06/29 20:08:09 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

typedef enum
{
	R,
	RR
}	t_direction;

typedef struct 	s_sizes
{
	size_t		rx;
	size_t		rrx;
	size_t		size;
	t_direction	direction;
}				 t_sizes;

typedef struct 				s_stack_elem
{
	int						number;
	int						index;
	t_bool					keep_in_stack;
	struct	s_stack_elem	*previous;
	struct	s_stack_elem	*next;

}							t_stack_elem;

typedef struct				s_stack
{
	t_stack_elem	*head;
	size_t			size;
	size_t			pairs;
	t_stack_elem	*markup_head;
}					t_stack;

typedef struct			s_command
{
	char				*name;
	struct s_command	*next;
}						t_command;

typedef struct			s_command_list
{
	t_command			*head;
}						t_command_list;

typedef	struct 			s_shift_info
{
	t_stack_elem		*a_elem;
	t_stack_elem		*b_elem;
	t_sizes				*lowest_r_a;
	t_sizes				*lowest_r_b;
	int					a_direction;
	int					b_direction;
	size_t				size;
	t_bool				is_set;
}						t_shift_info;

void			ft_print_stacks(t_stack *stack_a, t_stack *stack_b);
int				ft_stoi(char *str);
void			terminate();
t_stack			*init_stack(void);
t_stack_elem    *create_elem(int number);
void    		add(t_stack *stack, t_stack_elem *elem);
t_bool  		has_duplicates(t_stack *stack);
t_bool  		not_int(char* s);
t_stack 		*parse(int ac, char** av);
void			index_stack(t_stack *stack);
void			markup(t_stack	*stack);
size_t			markup_stack(t_stack *stack, t_stack_elem *markup_head);
t_command_list	*init_command_list(void);
t_command_list	*solve(t_stack	*stack);
t_command		*create_command(const char *name);
void			add_command(t_command_list *list, t_command *command);
void 			sx(t_stack *stack, char *arg, t_command_list *list);
void			px(t_stack	*to, t_stack *from, const char *name, t_command_list *list);
void			rx(t_stack *stack, const char *name, t_command_list *list);
void			rr(t_stack *a, t_stack *b, const char *name, t_command_list *list);
void			rrx(t_stack *stack, const char *name, t_command_list *list);
void			rrr(t_stack *a, t_stack *b, const char *name, t_command_list *list);
void			solve_a(t_stack *a_stack, t_stack *b_stack, t_command_list *command_list);
void			push(t_stack *stack, t_stack_elem *popped);
t_stack_elem 	*pop(t_stack *stack);
t_command		*create_command(const char *name);
void			add_command(t_command_list *list,
					t_command *command);
void			solve_b(t_stack	*a_stack, t_stack *b_stack,
				t_command_list	*command_list);
void 			opt_direction(t_stack *a_stack, t_stack *b_stack,
				t_shift_info *shift_info);

#endif
