#include "push_swap.h"

void double_check(int *tab, int size, t_list **stack_a, t_list **stack_b)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] == tab[i + 1])
			{
					write(2, "Error\n", 6);
					free(tab);
					ft_memory_heaven(stack_a, stack_b);
					exit(EXIT_FAILURE);
			}
		i++;
	}
}

static void	swap_tab(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size < 2)
		return ;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap_tab(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

int	*copy_cat(t_list *lst, int size)
{
    t_list *cursor;
	int *tab;
	int i;

	i = 0;
	size = ft_lstsize(lst);
	tab = malloc(size * sizeof(int *));
	if (!tab)
		return (NULL);
    cursor = lst;
	/* Copy */

    while (i < size)
    {
        tab[i] = cursor->content;
        cursor = cursor->next;
        i++;
    }
	/* Trie affichage */

    sort_int_tab(tab, size);
    return tab;
}

void indexation(t_list **stack_a, t_list **stack_b)
{
	t_list *head;
	int *tab;
	int size;
	int i;

	size = ft_lstsize(*stack_a);
	tab = copy_cat(*stack_a, size);
	head = *stack_a;
    i = 0;
	double_check(tab, size, stack_a, stack_b);
	while (1)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] == (*stack_a)->content)
			{
				(*stack_a)->index = i;
				break;
			}
			i++;
		}
		(*stack_a) = (*stack_a)->next;
		if (head == (*stack_a))
			break;
	}
	free(tab);
}
/*

	#1 Boucle : Avancer sur chaque element tmp jusqu'a lst = head / NULL si simplement chaine
		#2 Boucle compare chaque element au contenue de la stack actuelle (doit trouver sinon un probleme)
			# Si trouver : reperer sont index dans tab grace a i

*/