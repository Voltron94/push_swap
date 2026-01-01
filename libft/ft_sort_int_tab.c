#include "libft.h"

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