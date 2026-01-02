/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:05:24 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/02 20:22:21 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	empty_string(char **s, int size)
{
	int	j;

	j = 1;
	while (j < size)
	{
		if (s[j][0] == '\0')
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	classic_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	argv_check(char **s, int size)
{
	int	i;
	int	j;

	j = 1;
	empty_string(s, size);
	while (j < size)
	{
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] == '-' && (s[j][i + 1] < '0' || s[j][i + 1] > '9'))
				classic_error();
			if (s[j][i] == '-')
				i++;
			if ((s[j][i] < '0' || s[j][i] > '9') && s[j][i] != ' ')
				classic_error();
			i++;
		}
		j++;
	}
}

void	fill_stack_a(int size, char **argv, t_list **stack_a)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(argv[i], argv, *stack_a)));
		i++;
	}
}
