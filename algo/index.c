#include "push_swap.h"

/*			Temporaire			*/


void	print_tab(int *tab, int size) // A supprimer
{
    ft_printf("\n");
	for (int i = 0; i < size; i++)
	{
		ft_printf("tab %i : %i \n", i, tab[i]);
	}
}

void	print_index(t_list *lst)
{
    t_list *cursor;

    cursor = lst;
    if (!lst)
        return;
    ft_printf("linked index : %i \n", cursor->index);
    if (cursor->next)
        cursor = cursor->next;
    while (cursor != lst)
    {
        ft_printf("linked index : %i \n", cursor->index);
        cursor = cursor->next;
    }
}


/*								*/


static void	swap_tab(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort_int_tab(int *tab, unsigned int size)
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
	tab = malloc(size * sizeof(int));
    cursor = lst;
	// ft_printf("\nstack a size : %i\n\n", size);

	/* Copy */

    while (i < size)
    {
        tab[i] = cursor->content;
        cursor = cursor->next;
        i++;
    }
	/* Trie affichage */

    sort_int_tab(tab, size);
	// print_tab(tab, size);
    return tab;
}

void indexation(t_list *lst)
{
	t_list *head;
	int *tab;
	int size;
	int i;

	size = ft_lstsize(lst);
	tab = copy_cat(lst, size);
	head = lst;
    i = 0;

    /* Indexation (remplace le contenue par l'index de sa place ! )*/
	while (1)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] == lst->content)
			{
				lst->index = i;
				break;
			}
			i++;
		}
		lst = lst->next;
		if (head == lst)
			break;
	}
}
/*

	#1 Boucle : Avancer sur chaque element tmp jusqu'a lst = head / NULL si simplement chaine
		#2 Boucle compare chaque element au contenue de la stack actuelle (doit trouver sinon un probleme)
			# Si trouver : reperer sont index dans tab grace a i

*/
// ft_printf("\n");
// ft_print_linked(lst);