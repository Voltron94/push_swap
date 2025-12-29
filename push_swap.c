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

void	fill_stack_a(int size, char **argv, t_list **stack_a)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(argv[i])));	//check 2 depuis atoi
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

	fill_stack_a(ft_arg_len(argument), argument, &stack_a);

	ft_printf("\n - [Avant]\n\n");
	ft_printf("\n============		stack A :	 ============\n\n");
	ft_print_linked(stack_a);
	ft_printf("\n============		stack B :	 ============\n\n");
	ft_print_linked(stack_b);

	if(ft_arg_len(argument) == 1)
		return (0);

	/* Zone de test */

	ft_printf("\n - [Instruction]\n\n");
	
	// push(&stack_a, &stack_b, 'a');
	// swap(&stack_a, &stack_b, 'a');
	// rotate(&stack_a, &stack_b, 'a');
	// reverse_rotate(&stack_a, &stack_b, 'a');

	// push(&stack_a, &stack_b, 'b');
    // rotate(&stack_a, &stack_b, 'a');

	indexation(stack_a);

	// ft_printf("\n - [Index] stack A \n\n");
	// print_index(stack_a);		//A supprimer

	// ft_printf("\n - [Radix] En cours... \n\n");
	radix(&stack_a, &stack_b);

	ft_printf("\n - [Apres]\n\n");
	ft_printf("\n============		stack A :	============\n\n");
	ft_print_linked(stack_a);
	ft_printf("\n============		stack B :	============\n\n");
	ft_print_linked(stack_b);
}