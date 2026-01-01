#include "libft.h"

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
	t_list *stack_a;
	t_list *stack_b;
	char **argument;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	argv_check(argv, argc);
	argument = all_for_one(argc, argv);
	fill_stack_a(ft_arg_len(argument), argument, &stack_a, &stack_b);
	if (ft_arg_len(argument) == 1)
	{
		ft_memory_heaven(&stack_a, &stack_b);
		free_tab(argument, ft_arg_len(argument));
		return (0);
	}
	free_tab(argument, ft_arg_len(argument));
	indexation(&stack_a, &stack_b);
	radix(&stack_a, &stack_b);

	ft_memory_heaven(&stack_a, &stack_b);
}