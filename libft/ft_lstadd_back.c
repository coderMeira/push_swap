<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:09:05 by fmeira            #+#    #+#             */
/*   Updated: 2021/03/03 18:31:39 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *n)
{
    if (lst)
    {
        if (*lst)
            ft_lstlast(*lst) -> next = new;
        else
            *lst = new;
    }
}

void ft_printlst(t_list *a)
{
    t_list  *current;
    int *p;

    p = current -> content;
    current = a;

    while (current)
    {
        printf("%d\n", *p);
        current = current -> next;
    }
}
