/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_cat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:42:20 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/01 21:16:35 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*copy_cat(t_list *lst, int size)
{
	t_list	*cursor;
	int		*tab;
	int		i;

	i = 0;
	size = ft_lstsize(lst);
	tab = malloc(size * sizeof(int));
	if (!tab)
		return (NULL);
	cursor = lst;
	while (i < size)
	{
		tab[i] = cursor->content;
		cursor = cursor->next;
		i++;
	}
	return (tab);
}
