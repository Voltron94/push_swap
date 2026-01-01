#include "libft.h"

void	push(t_list **stack_a, t_list **stack_b, char choice)
{
	if (choice == 'a')
	{
		ft_printf("pa\n");
		ft_pa(stack_a, stack_b);
	}
	if (choice == 'b')
	{
		ft_printf("pb\n");
		ft_pb(stack_a, stack_b);
	}
}

void	swap(t_list **stack_a, t_list **stack_b, char choice)
{
	if (choice == 'a')
	{
		ft_printf("sa\n");
		ft_sa(stack_a);
	}
	if (choice == 'b')
	{
		ft_printf("sb\n");
		ft_sb(stack_b);
	}
	if (choice == 's')
	{
		ft_printf("ss\n");
		ft_ss(stack_a, stack_b);
	}
}

void	rotate(t_list **stack_a, t_list **stack_b, char choice)
{
	if (choice == 'a')
	{
		ft_printf("ra\n");
		ft_ra(stack_a);
	}
	if (choice == 'b')
	{
		ft_printf("rb\n");
		ft_rb(stack_b);
	}
	if (choice == 'r')
	{
		ft_printf("rr\n");
		ft_rr(stack_a, stack_b);
	}
}

void	reverse_rotate(t_list **stack_a, t_list **stack_b, char choice)
{
	if (choice == 'a')
	{
		ft_printf("rra\n");
		ft_rra(stack_a);
	}
	if (choice == 'b')
	{
		ft_printf("rrb\n");
		ft_rrb(stack_b);
	}
	if (choice == 'r')
	{
		ft_printf("rrr\n");
		ft_rrr(stack_a, stack_b);
	}
}