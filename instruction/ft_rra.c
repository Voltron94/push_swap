#include "libft.h"

void	ft_rra(t_list **stack_a)
{
	t_list *head_a;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	head_a = ft_unlink_tail(stack_a);
    ft_push_h(stack_a, head_a);
}

void	ft_rrb(t_list **stack_b)
{
	t_list *head_b;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	head_b = ft_unlink_tail(stack_b);
    ft_push_h(stack_b, head_b);
}

void ft_rrr(t_list **stack_a, t_list **stack_b)
{
    ft_rra(stack_a);
    ft_rrb(stack_b);
}