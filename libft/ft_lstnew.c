/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 17:33:13 by fmeira            #+#    #+#             */
/*   Updated: 2021/03/03 18:34:13 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = (t_list	*)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = (NULL);
	return (head);
}
