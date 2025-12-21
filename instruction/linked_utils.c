/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:58:06 by eprieur           #+#    #+#             */
/*   Updated: 2025/12/21 16:04:23 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	link part	*/

void	ft_push_h(t_list **stack, t_list *node)	// Utilite : pa/pb
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

void	ft_push_tail(t_list **stack, t_list *node)	//	Ne gere pas le cas stack = 1 element
{													//	Il est gerer au prealable dans ra, rb
	t_list	*head;									//	Utilite : ra/rb
	t_list	*tail;

	head = *stack;
	
	tail = head->previous;
	tail->next = node;
	head->previous = node;
	node->next = head;
	node->previous = tail;
}

/*	Unlink part	*/

t_list	*ft_unlink_h(t_list **stack)	// Utilite : pa/pb
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

t_list	*ft_unlink_tail(t_list **stack)	//	Ne gere pas le cas stack = 1 element
{										//	Cette fonction n'est jamais cense etre appeler dans se cas
	t_list	*head;						//	Fonction rra/rrb
	t_list  *before_tail;
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
	head->previous = before_tail;	//changer le previous de head, depart de la queue actuelle
	before_tail->next = head;
	return (tail);
}