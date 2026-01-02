/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:55:05 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/02 17:05:01 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_max_bits(t_list *stack)
{
	int	bit_size;
	int	max_val;

	bit_size = 0;
	max_val = ft_lstsize(stack) - 1;
	while (max_val > 1)
	{
		bit_size++;
		max_val /= 2;
	}
	return (bit_size);
}

void	radix(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	tmp;
	int	size;
	int	max_bit;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bit = get_max_bits(*stack_a);
	if (size == 2 || size == 3)
		spe_mov(stack_a, stack_b, size);
	while (i <= max_bit && size != 2 && size != 3)
	{
		tmp = size;
		while (tmp-- > 0)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				push(stack_a, stack_b, 'b');
			else
				rotate(stack_a, stack_b, 'a');
		}
		while (*stack_b)
			push(stack_a, stack_b, 'a');
		i++;
	}
}
