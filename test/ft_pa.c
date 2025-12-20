#include "push_swap.h"

static void	ft_pa_case2(t_list **stack_a, t_list **stack_b)	// case, stack b = one element
{
	t_list *tail_a;
	t_list *tail_b;
	t_list *b_second;

	tail_a = (*stack_a)->previous;
	tail_b = (*stack_b)->previous;
	b_second = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	(*stack_a)->previous = *stack_b;
	tail_a->next = *stack_b;
	*stack_a = *stack_b;
	*stack_b = NULL;
	ft_printf("pa\n");
}

static void	ft_pa_case1(t_list **stack_a, t_list **stack_b) // case, stack a = one element
{
	t_list *tail_b;
	t_list *b_second;

	tail_b = (*stack_b)->previous;
	b_second = (*stack_b)->next;
	(*stack_b)->next = (*stack_a);
	(*stack_b)->previous = (*stack_a);
	(*stack_a)->next = (*stack_b);
	(*stack_a)->previous = (*stack_b);
	b_second->previous = tail_b;
	tail_b->next = b_second;
	*stack_a = *stack_b;
	*stack_b = b_second;
	ft_printf("pa\n");
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tail_a;
	t_list	*tail_b;
	t_list	*b_second;

	if (!(*stack_b))
		return ;
	tail_a = (*stack_a)->previous;
	tail_b = (*stack_b)->previous;
	b_second = (*stack_b)->next;
	if (!(*stack_a)->next) // si a un seul element
	{
		ft_pa_case1(stack_a, stack_b);
		return ;
	}
	if (!(*stack_b)->next) // b un element
	{
		ft_pa_case2(stack_a, stack_b);
		return;
	}
	// cas classique
	(*stack_b)->next = *stack_a;
	(*stack_b)->previous = (*stack_a)->previous;
	(*stack_a)->previous = *stack_b; //l'adresse de l'ancien  top A a pour previous le nv top
	tail_a->next = *stack_b;
	b_second->previous = tail_b;
	tail_b->next = b_second;
	*stack_a = *stack_b;
	*stack_b = b_second;
	ft_printf("pa\n");
}

/*
	A prendre en compte !
		Si stack a = 1 element 
		Si stack a est vide
		Si stack b = 1 element
		Si stack a et stack b = 1 element 
*/