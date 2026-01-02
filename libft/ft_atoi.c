/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:15:22 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/02 20:31:47 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

void	error_exit(t_list *stack_a, char **tab)
{
	free_tab(tab, ft_arg_len(tab));
	ft_lstclear(&stack_a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *nptr, char **tab, t_list *stack_a)
{
	int		i;
	int		c;
	long	nb;

	i = 0;
	c = 1;
	nb = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] != '\0' && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			c = -c;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	if (nb > INT_MAX || nb < INT_MIN)
		error_exit(stack_a, tab);
	return (nb * c);
}
