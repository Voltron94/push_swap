#include "push_swap.h"

int	argv_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '"' && s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	fill_stack_a(int argc, char **argv, t_list **stack_a)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(argv[i])));	//check 2 depuis atoi
		i++;
	}
}

void	tmp(int n, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_lstadd_back(stack_b, ft_lstnew(i));
		i++;
	}
}

char	**all_for_one(int argc, char **argv)
{
	int		i;
	char	*ns;
	char	**ns_split;

	i = 1;
	ns = ft_strdup("");
	while (i < argc)
	{
		ns = ft_strjoin(ns, argv[i]);
		i++;
	}
	ns_split = ft_split(ns, ' ');
	// for (int i = 0;  ns_split[i]; i++)
	// {
	//     ft_printf("ns_split : %s \n", ns_split[i]);
	// }
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
			return (write(2, "error", 5));
		i++;
	}
	argument = all_for_one(argc, argv);
	fill_stack_a(ft_arg_len(argument), argument, &stack_a);
	tmp(5, &stack_b); //fill b pour des tests

	ft_printf("\n - [Avant]\n\n");
	ft_printf("\n============		list A :	 ============\n\n");
	ft_print_linked(stack_a);
	ft_printf("\n============		list B :	 ============\n\n");
	ft_print_linked(stack_b);
	
	/* Zone de test*/
	ft_printf("\n - [Instruction]\n\n");
	
	reverse_rotate(&stack_a, &stack_b, 'a');	//ne fonctionne pas deux fois si stack = 2
	reverse_rotate(&stack_a, &stack_b, 'a');
	// push(&stack_a, &stack_b, 'a');
	// swap(&stack_a, &stack_b, 'a');
	// rotate(&stack_a, &stack_b, 'a');

	ft_printf("\n - [Apres]\n\n");
	ft_printf("\n============		list A :	============\n\n");
	ft_print_linked(stack_a);
	ft_printf("\n============		list B :	============\n\n");
	ft_print_linked(stack_b);
}