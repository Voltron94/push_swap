#include "checker.h"

void    print_index(t_list *lst)
{
    t_list *cursor;

    cursor = lst;
    if (!lst)
        return;
    ft_printf("linked index : %i \n", cursor->content);
    if (cursor->next)
        cursor = cursor->next;
    while (cursor != lst)
    {
        ft_printf("linked index : %i \n", cursor->content);
        cursor = cursor->next;
    }
}

void    print_tab(int *tab, int size) // A supprimer
{
    ft_printf("\n");
	ft_printf("print tab : \n");
    for (int i = 0; i < size; i++)
    {
        ft_printf("tab %i : %i \n", i, tab[i]);
    }
}

void null_check(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b)
	{
		write(2, "KO\n", 3);
		ft_memory_heaven(stack_a, stack_b);
		exit(EXIT_FAILURE);
	}
}

void sort_check(int *tab, int size, t_list **stack_a, t_list **stack_b)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] >= tab[i + 1])
		{
			write(2, "KO\n", 3);
			free(tab);
			ft_memory_heaven(stack_a, stack_b);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;
	char *s;
	int *tab;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	argv_check(argv, argc);
	fill_stack_a(argc - 1, argv + 1, &stack_a, &stack_b);

	s = get_next_line(0);
	while (s != NULL)
	{
		action(s, ft_strlen(s) - 1, &stack_a, &stack_b);
		free(s);
		s = get_next_line(0);
	}
	
	tab = copy_cat(stack_a , ft_lstsize(stack_a));

	print_tab(tab, ft_lstsize(stack_a));

	sort_check(tab, ft_lstsize(stack_a), &stack_a, &stack_b);
	free(tab);

	null_check(&stack_a, &stack_b);

	ft_printf("OK\n");
	print_index(stack_a);
	
	ft_memory_heaven(&stack_a, &stack_b);
	return (0);
}