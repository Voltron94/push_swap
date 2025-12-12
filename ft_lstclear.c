/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:37:27 by eprieur           #+#    #+#             */
/*   Updated: 2025/11/18 21:20:23 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	head = *lst;
	tmp = *lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		(*del)(head->content);
		free(head);
		head = tmp;
	}
	*lst = NULL;
}
