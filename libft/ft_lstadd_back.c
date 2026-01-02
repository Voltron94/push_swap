/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:23:39 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/02 17:23:39 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cursor;
	t_list	*head;

	cursor = *lst;
	head = *lst;
	if (cursor)
	{
		while (cursor->next != *lst && cursor->next)
		{
			cursor = cursor->next;
		}
		new->previous = cursor;
		cursor->next = new;
		new->next = head;
		head->previous = new;
	}
	else if (!cursor)
		*lst = new;
}
