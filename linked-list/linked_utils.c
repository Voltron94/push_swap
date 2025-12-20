/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:58:06 by eprieur           #+#    #+#             */
/*   Updated: 2025/12/20 18:34:02 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_erase_h(t_list **stack)
{
	t_list	*head;
	t_list	*second;
	t_list	*tail;

	if (!stack || !(*stack))
		return (NULL);
	head = *stack;
	second = head->next;
	tail = head->previous;
	if (head->next == NULL)
	{
		*stack = NULL;
		head->next = NULL;
		head->previous = NULL;
		return (head);
	}
	head->next = NULL;
	head->previous = NULL;
	second->previous = tail;
	tail->next = second;
	*stack = second;
	return (head);
}

void	ft_push_h(t_list **stack, t_list *node)
{
	t_list	*head;
	t_list	*second;
	t_list	*tail;

	head = *stack;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	second = head->next;
	tail = head->previous;
	if (head->next == NULL)
	{
		node->next = head;
		node->previous = head;
		head->next = node;
		*stack = node;
		return ;
	}
	node->next = head;
	node->previous = head->previous;
	tail->next = node;
	*stack = node;
}
