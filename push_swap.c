/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:31:18 by eprieur           #+#    #+#             */
/*   Updated: 2026/01/02 20:32:45 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sort_check(int size, t_list **stack_a, t_list **stack_b)
{
	int	*tab;
	int	i;

	i = 0;
	tab = copy_cat(*stack_a, ft_lstsize(*stack_a));
	while (i < size - 1)
	{
		if (tab[i] >= tab[i + 1])
		{
			free(tab);
			return (0);
		}
		i++;
	}
	free(tab);
	ft_memory_heaven(stack_a, stack_b);
	return (1);
}

char	**all_for_one(int argc, char **argv)
{
	int		i;
	char	*tmp;
	char	*ns;
	char	**ns_split;

	i = 1;
	ns = ft_strdup("");
	while (i < argc)
	{
		tmp = ns;
		ns = ft_strjoin(ns, argv[i]);
		free(tmp);
		i++;
	}
	ns_split = ft_split(ns, ' ');
	free(ns);
	return (ns_split);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**argument;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	argv_check(argv, argc);
	argument = all_for_one(argc, argv);
	fill_stack_a(ft_arg_len(argument), argument, &stack_a);
	if (ft_arg_len(argument) == 1)
	{
		ft_memory_heaven(&stack_a, &stack_b);
		free_tab(argument, ft_arg_len(argument));
		return (0);
	}
	free_tab(argument, ft_arg_len(argument));
	indexation(&stack_a, &stack_b);
	if (sort_check(ft_lstsize(stack_a), &stack_a, &stack_b))
		return (0);
	radix(&stack_a, &stack_b);
	ft_memory_heaven(&stack_a, &stack_b);
}
// ft_print_linked(stack_a);
// void	ft_print_linked(t_list *lst)
// {
// 	t_list	*cursor;

// 	cursor = lst;
// 	if (!lst)
// 		return ;
// 	ft_printf("linked content : %i \n", cursor->content);
// 	if (cursor->next)
// 		cursor = cursor->next;
// 	while (cursor != lst)
// 	{
// 		ft_printf("linked content : %i \n", cursor->content);
// 		cursor = cursor->next;
// 	}
// }
