/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:11:29 by fmeira            #+#    #+#             */
/*   Updated: 2021/06/09 01:56:39 by fmeira           ###   ########.fr       */
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
	false,
	true
}	t_bool;

typedef struct 				s_stack_elem
{
	int						number;
	ssize_t					index;
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
t_command_list	*solve(t_stack	*stack);
t_command		*create_command(const char *name);
void			add_command(t_command_list *list, t_command *command);
void 			sx(t_stack *stack, char *arg, t_command_list *list);
static void 	swap(t_stack_elem *first, t_stack_elem *second, t_stack *stack);


#endif
