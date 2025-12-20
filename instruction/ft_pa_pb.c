#include "push_swap.h"

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list *head_b;	//la node a ajouter
	
	if (!stack_b || !(*stack_b))
		return;
	head_b = ft_erase_h(stack_b);

	ft_push_h(stack_a, head_b);
	ft_printf("pa\n");
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list *head_a;	//la node a ajouter
	
	if (!stack_a || !(*stack_a))
		return;
	head_a = ft_erase_h(stack_a);
	ft_push_h(stack_b, head_a);
	ft_printf("pb\n");
}

/*
	A prendre en compte !
		Si stack a = 1 element					[x]
		Si stack a est vide						[x]
		Si stack b = 1 element					[x]
		Si stack a et stack b = 1 element 		[x]
*/