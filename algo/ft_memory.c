#include "push_swap.h"

void	free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_memory_heaven(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a);
	if (*stack_b)
		ft_lstclear(stack_b);
}

// gerer cas 2 element