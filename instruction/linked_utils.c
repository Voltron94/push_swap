/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:58:06 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/02 17:36:58 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_h(t_list **stack, t_list *node)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	if (!*stack)
	{
		*stack = node;
		return ;
	}
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

void	ft_push_tail(t_list **stack, t_list *node)
{
	t_list	*head;
	t_list	*tail;

	head = *stack;
	tail = head->previous;
	tail->next = node;
	head->previous = node;
	node->next = head;
	node->previous = tail;
}

t_list	*ft_unlink_h(t_list **stack)
{
	t_list	*head;
	t_list	*second;
	t_list	*tail;

	if (!stack || !(*stack))
		return (NULL);
	head = *stack;
	second = head->next;
	tail = head->previous;
	if (head->next == head || head->next == NULL)
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

t_list	*ft_unlink_tail(t_list **stack)
{
	t_list	*head;
	t_list	*before_tail;
	t_list	*tail;

	if (!stack || !(*stack))
		return (NULL);
	head = *stack;
	tail = head->previous;
	before_tail = tail->previous;
	if (head->next == tail)
	{
		head->next = NULL;
		head->previous = NULL;
		tail->next = NULL;
		tail->previous = NULL;
		return (tail);
	}
	tail->next = NULL;
	tail->previous = NULL;
	head->previous = before_tail;
	before_tail->next = head;
	return (tail);
}
