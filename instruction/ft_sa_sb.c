/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:35:24 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/02 17:35:30 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sa(t_list **lst)
{
	t_list	*second_node;
	t_list	*third_node;
	t_list	*last_node;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	second_node = (*lst)->next;
	last_node = (*lst)->previous;
	if (second_node->next == *lst)
	{
		*lst = second_node;
		return ;
	}
	third_node = second_node->next;
	third_node->previous = *lst;
	(*lst)->next = third_node;
	second_node->next = *lst;
	second_node->previous = (*lst)->previous;
	(*lst)->previous = second_node;
	last_node->next = second_node;
	*lst = second_node;
}

void	ft_sb(t_list **lst)
{
	t_list	*second_node;
	t_list	*third_node;
	t_list	*last_node;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	second_node = (*lst)->next;
	last_node = (*lst)->previous;
	if (second_node->next == *lst)
	{
		*lst = second_node;
		return ;
	}
	third_node = second_node->next;
	third_node->previous = *lst;
	(*lst)->next = third_node;
	second_node->next = *lst;
	second_node->previous = (*lst)->previous;
	(*lst)->previous = second_node;
	last_node->next = second_node;
	*lst = second_node;
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}
