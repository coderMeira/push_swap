<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:08:03 by fmeira            #+#    #+#             */
/*   Updated: 2021/03/03 13:53:31 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
=======

#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
    t_list  *aux;

    aux = lst;
    while (aux -> next != NULL)
        aux = aux -> next;

    return (aux);
}
int main()                                                   
{                                                            
    t_list *head;                                            
    t_list *dois;                                            
    t_list *tres;          
    int     three;
    int     *p;

    three = 55555;
    p = &three;
    head = (t_list*)malloc(sizeof(t_list));                  
    dois = (t_list*)malloc(sizeof(t_list));                  
    tres = (t_list*)malloc(sizeof(t_list));                  
                                                             
   // head -> (int)content = 1;                              
    head -> next = dois;                                     
                                                             
    //dois -> (int)content = 2;                              
    dois -> next = tres;                                     
                                                             
    tres -> content = (int *)p;                              
    tres -> next = NULL;                                     
                                                             
    printf("%d\n", *(int *)ft_lstlast(head) -> content);                                                             
    free(head);                                              
    free(dois);                                              
    free(tres);                                              

    return 0;
>>>>>>> 6241f455eadd3a21c353f96b66fe820b1e264cda
}
