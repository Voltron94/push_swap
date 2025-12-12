/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voltron <voltron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:35:04 by eprieur           #+#    #+#             */
/*   Updated: 2025/11/16 18:57:39 by voltron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}
/*
	si lst est null et qu'on lui demande 
	de regarder le next il va regarder un lieu memoire indefinie
	d'ou la première condition
*/
