/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:35:12 by eprieur           #+#    #+#             */
/*   Updated: 2025/12/12 10:26:46 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*List;

	List = ft_lstnew(40);
	ft_lstadd_front(&List, ft_lstnew(41));
	ft_lstadd_front(&List, ft_lstnew(42));
	printf("%i", printLst(List));
	return (0);
}
*/
