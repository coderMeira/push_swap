<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:06:57 by fmeira            #+#    #+#             */
/*   Updated: 2021/03/03 18:41:36 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = lst;
	if (!lst)
		return (0);
	while (aux != NULL)
	{
		i++;
		aux = aux->next;
	}
	return (i);
=======

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int     i;
    t_list  *aux;

    i = 0;
    aux = lst;
    if (!lst)
        return (0);
    while (aux != NULL)
    {
        i++;
        aux = aux -> next;
    }
    return (i);
}

int main()
{
    t_list *head;
    t_list *dois;
    t_list *tres;

    head = (t_list*)malloc(sizeof(t_list));
    dois = (t_list*)malloc(sizeof(t_list));
    tres = (t_list*)malloc(sizeof(t_list));

   // head -> (int)content = 1;
    head -> next = dois;

    //dois -> (int)content = 2;
    dois -> next = tres;

    //tres -> (int)content = 3;
    tres -> next = NULL;
    
    printf("%d\n", ft_lstsize(head));

    free(head);
    free(dois);
    free(tres);

    return 0;
>>>>>>> 6241f455eadd3a21c353f96b66fe820b1e264cda
}
