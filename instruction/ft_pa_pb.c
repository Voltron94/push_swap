/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:31:24 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/02 17:32:55 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_b;

	if (!stack_b || !(*stack_b))
		return ;
	head_b = ft_unlink_h(stack_b);
	ft_push_h(stack_a, head_b);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;

	if (!stack_a || !(*stack_a))
		return ;
	head_a = ft_unlink_h(stack_a);
	ft_push_h(stack_b, head_a);
}
