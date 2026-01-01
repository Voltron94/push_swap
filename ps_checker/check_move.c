#include "checker.h"

void	action_next(char *s, int size, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	if (s[i])
	{
		if (s[i] == 'r' && s[i + 1] == 'r' && s[i + 2] == 'r' && size == 3)
			ft_rrr(stack_a, stack_b);
		else if (s[i] == 's' && s[i + 1] == 's' && size == 2)
			ft_ss(stack_a, stack_b);
		else if (s[i] == 's' && s[i + 1] == 'a' && size == 2)
			ft_sa(stack_a);
		else if (s[i] == 's' && s[i + 1] == 'b' && size == 2)
			ft_sb(stack_b);
		else
		{
			write(2, "KO\n", 3);
			ft_memory_heaven(stack_a, stack_b);
			exit(EXIT_FAILURE);
		}
	}
}

void	action(char *s, int size, t_list **stack_a, t_list **stack_b)
{
	int i;

	i = 0;
	if (s[i])
	{
		if (s[i] == 'p' && s[i + 1] == 'a' && size == 2)
			ft_pa(stack_a, stack_b);
		else if (s[i] == 'p' && s[i + 1] == 'b' && size == 2)
			ft_pb(stack_a, stack_b);
		else if (s[i] == 'r' && s[i + 1] == 'a' && size == 2)
			ft_ra(stack_a);
		else if (s[i] == 'r' && s[i + 1] == 'b' && size == 2)
			ft_rb(stack_b);
		else if (s[i] == 'r' && s[i + 1] == 'r' && s[i + 2] == 'a' && size == 3)
			ft_rra(stack_a);
		else if (s[i] == 'r' && s[i + 1] == 'r' && s[i + 2] == 'b' && size == 3)
			ft_rrb(stack_b);
		else
			action_next(s, size, stack_a, stack_b);
	}
}