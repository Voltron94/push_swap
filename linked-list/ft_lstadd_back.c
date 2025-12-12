/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:21:36 by eprieur           #+#    #+#             */
/*   Updated: 2025/12/12 10:26:46 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cursor;

	cursor = *lst;
	if (cursor)
	{
		while (cursor->next != NULL)
		{
			cursor = cursor->next;
		}
		cursor->next = new;
	}
	else if (!cursor)
		*lst = new;
}
/*
	OU

	while (lst[0]->next != 0)
	{
		lst[0] = lst[0]->next;
	}
	lst[0]->next = new;

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cursor;

	cursor = *lst;
	while (cursor->next != 0)
	{
		cursor = cursor->next;
	}
	cursor->next = new;
}


*/
/*
int	main(void)
{
	t_list	*list;

	list = ft_lstnew(42);
	ft_lstadd_back(&list, ft_lstnew(44));
	printLst(list);
	return (0);
}
*/
