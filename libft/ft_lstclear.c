/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:23:53 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/02 17:24:08 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	current = *lst;
	tmp = *lst;
	if ((*lst)->previous)
		(*lst)->previous->next = NULL;
	while (current)
	{
		tmp = tmp->next;
		free(current);
		current = tmp;
	}
	*lst = NULL;
}
