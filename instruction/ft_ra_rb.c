#include "push_swap.h"

void	ft_ra(t_list **stack_a)
{
	t_list	*head_a;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	head_a = ft_unlink_h(stack_a);
	ft_push_tail(stack_a, head_a);
}

void	ft_rb(t_list **stack_b)
{
	t_list	*head_b;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	head_b = ft_unlink_h(stack_b);
	ft_push_tail(stack_b, head_b);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}