/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:37:41 by fmeira            #+#    #+#             */
/*   Updated: 2021/05/29 19:54:13 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void terminate()
{
    ft_putendl_fd("Error", 2);
    exit(1);
}

t_stack_elem    *create_elem(int number)
{
    t_stack_elem    *new;

    new = (t_stack_elem *)malloc(sizeof(t_stack_elem));
    if (!new)
        terminate();
    new->number = number;
    new->index = -1;
    new->keep_in_stack = false;
    new->previous = NULL;
    new->next = NULL;
    return (new);
}

void    add(t_stack *stack, t_stack_elem *elem)
{
    t_stack_elem *tail;
    if (stack && elem)
    {
        if (!stack->head)
        {
            stack->head = elem;
            stack->head->next = stack->head;
            stack->head->previous = stack->head;
        }
        else
        {
            tail = stack->head->previous;
            elem->previous = tail;
            tail->next = elem;
            elem->next = stack->head;
            stack->head->previous = elem;
        }
        stack->size++;
    }
}

t_bool  has_duplicates(t_stack *stack)
{
    size_t          i;
    t_stack_elem    *current_i;
    t_stack_elem    *current_j;

    i = 0;
    current_i = stack->head;
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
    return (false);
}

t_bool  not_int(char* s)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(s);
    if (s[i] == '-' && ft_isdigit(s[1]))
        i++;
    while (i < len)
    {
        if (!(ft_isdigit(s[i++])))
            return (true);
    }
    return (false);
}

t_stack *parse(int ac, char** av)
{
    int     i;
    t_stack *stack;

    i = 1;
    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        terminate();
    stack->head = NULL;
    stack->size = 0;
    stack->pairs = 0;
    stack->markup_head = NULL;
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
