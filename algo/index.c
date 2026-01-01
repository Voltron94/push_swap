#include "libft.h"

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

void indexation_next(int *tab, int size, t_list **stack_a)
{
	t_list *head;
	int i;

	i = 0;
	head = *stack_a;
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
}

void indexation(t_list **stack_a, t_list **stack_b)
{
	int *tab;
	int size;

	size = ft_lstsize(*stack_a);
	tab = copy_cat(*stack_a, size);
	sort_int_tab(tab, size);

	double_check(tab, size, stack_a, stack_b);
	indexation_next(tab, size, stack_a);

	free(tab);
}
/*

	#1 Boucle : Avancer sur chaque element tmp jusqu'a lst = head / NULL si simplement chaine
		#2 Boucle compare chaque element au contenue de la stack actuelle (doit trouver sinon un probleme)
			# Si trouver : reperer sont index dans tab grace a i

*/