/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:11:29 by fmeira            #+#    #+#             */
/*   Updated: 2021/05/29 19:52:01 by fmeira           ###   ########.fr       */
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

int	ft_stoi(char *str);
void terminate();
t_stack_elem    *create_elem(int number);
void    add(t_stack *stack, t_stack_elem *elem);
t_bool  has_duplicates(t_stack *stack);
t_bool  not_int(char* s);
t_stack *parse(int ac, char** av);

#endif
