/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:27:55 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/02 17:28:33 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_tab(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size < 2)
		return ;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap_tab(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}
