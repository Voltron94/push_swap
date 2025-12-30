#include "push_swap.h"

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr, t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		c;
	long	nb;

	i = 0;
	c = 1;
	nb = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] != '\0' && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			c = -c;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (nb > INT_MAX)
	{
		write(2, "Error\n", 6);
		ft_memory_heaven(stack_a, stack_b);		// liberer toute la memoire actuelle
		exit(EXIT_FAILURE);
	}
	return (nb * c);
}
