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

void fill_stack_a(int argc, char **argv, t_list **stack_a)
{
	int i;

	i = 1;
    while (i < argc)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(argv[i]))); 
		i++;
	}
}

char *all_for_one(int argc, char **argv)
{
	int i;
	char *ns;

	i = 1;
	ns = ft_strdup("");
	while (i < argc)
	{
		ns = ft_strjoin(ns, argv[i]);
		i++;
	}
	ft_printf("%s", ns);
	return (ns);
}

int	main(int argc, char **argv)
{
	t_list *stack_a;	//doit etre ranger a la fin
	//t_list *stack_b;	//sert de stockage temporaire
	int i;

	i = 1;
	stack_a = NULL;
	if (argc == 1)  //aucun argument
		return (0);
	while (i < argc)
	{
		if (!argv_check(argv[i]))
			return (write(1, "error", 5));
		i++;
	}

    fill_stack_a(argc, argv, &stack_a);
	all_for_one(argc, argv);
	//ft_lst_rotate(&stack_a);
	ft_print_linked(stack_a);
	// printf("%d", a->content);
}