#include "push_swap.h"

int	argv_check(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' && (s[i + 1] >= '0' && s[i + 1] <= '9'))
		i++;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	fill_stack_a(int size, char **argv, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(argv[i], stack_a, stack_b)));	//check 2 depuis atoi
		i++;
	}
}

char	**all_for_one(int argc, char **argv)
{
	int		i;
	char 	*tmp;
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
	t_list *stack_a;
	t_list *stack_b;
	char **argument;
	int i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	while (i < argc)	//check 1
	{
		if (!argv_check(argv[i]))
			return (write(2, "Error\n", 6));
		i++;
	}
	argument = all_for_one(argc, argv);

/*		Affichage		*/

	fill_stack_a(ft_arg_len(argument), argument, &stack_a, &stack_b);

	ft_printf("\n - [Avant]\n\n");
	ft_printf("\n============		stack A :	 ============\n\n");
	ft_print_linked(stack_a);
	ft_printf("\n============		stack B :	 ============\n\n");
	ft_print_linked(stack_b);

	if(ft_arg_len(argument) == 1)
	{
		ft_memory_heaven(&stack_a, &stack_b);
		free_tab(argument, ft_arg_len(argument));
		return (0);
	}

	indexation(stack_a);
	radix(&stack_a, &stack_b);

	ft_printf("\n - [Apres]\n\n");
	ft_printf("\n============		stack A :	============\n\n");
	ft_print_linked(stack_a);
	ft_printf("\n============		stack B :	============\n\n");
	ft_print_linked(stack_b);

	ft_memory_heaven(&stack_a, &stack_b);
	free_tab(argument, ft_arg_len(argument));
}