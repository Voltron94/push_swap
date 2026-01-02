/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:31:35 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/02 18:02:24 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	double_check(int *tab, int size, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] == tab[i + 1])
		{
			write(2, "Error\n", 6);
			free(tab);
			ft_memory_heaven(stack_a, stack_b);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	indexation_next(int *tab, int size, t_list **stack_a)
{
	t_list	*head;
	int		i;

	i = 0;
	head = *stack_a;
	while (1)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] == (*stack_a)->content)
			{
				(*stack_a)->index = i;
				break ;
			}
			i++;
		}
		(*stack_a) = (*stack_a)->next;
		if (head == (*stack_a))
			break ;
	}
}

void	indexation(t_list **stack_a, t_list **stack_b)
{
	int	*tab;
	int	size;

	size = ft_lstsize(*stack_a);
	tab = copy_cat(*stack_a, size);
	sort_int_tab(tab, size);
	double_check(tab, size, stack_a, stack_b);
	indexation_next(tab, size, stack_a);
	free(tab);
}
