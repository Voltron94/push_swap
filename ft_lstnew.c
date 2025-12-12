/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:47:48 by eprieur           #+#    #+#             */
/*   Updated: 2025/12/12 11:15:11 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst == 0)
		return (0);
	lst->content = content;
	lst->next = 0;
	return (lst);
}
/*
int	main(void)
{
	int	nb;

	nb = 42;
	ft_lstnew(&nb);
	return (0);
}
*/