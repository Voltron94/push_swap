/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:13:05 by eprieur           #+#    #+#             */
/*   Updated: 2025/12/12 10:43:37 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*lstnew_(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = 0;
	return (lst);
}

static void	lstclear_(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	head = *lst;
	tmp = *lst;
	while (tmp != 0)
	{
		tmp = tmp->next;
		(*del)(head->content);
		free(head);
		head = tmp;
	}
	*lst = NULL;
}

static void	lstadd_back_(t_list **lst, t_list *new)
{
	t_list	*cursor;

	cursor = *lst;
	if (cursor)
	{
		while (cursor->next != 0)
			cursor = cursor->next;
		cursor->next = new;
	}
	else if (!cursor)
		*lst = new;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	new_lst = 0;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = lstnew_(new_content);
		if (!new_node)
		{
			(*del)(new_content);
			lstclear_(&new_lst, del);
			return (0);
		}
		lstadd_back_(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/*


t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	new_lst = 0;
	while (lst) 	//Tant que Lst n'est pas nul
	{
		new_content = f(lst->content);//sinon supprimer le content ne sera pas possible
		new_node = lstnew_(new_content);
		if (!new_node)	// Si echec allocation
		{
			(*del)(new_content); 
			lstclear_(&new_lst, del);
			return (0);
		}
		lstadd_back_(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

*/
