/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:24:32 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/02 17:27:30 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		l;
	t_list	*cursor;

	l = 0;
	cursor = lst;
	if (cursor->next != NULL)
	{
		l++;
		cursor = cursor->next;
	}
	while (cursor != lst)
	{
		l++;
		cursor = cursor->next;
	}
	return (l);
}
