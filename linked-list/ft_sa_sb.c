#include "push_swap.h"

/*Echange les deux premier element de la list*/

/* Stack A */
void	ft_sa(t_list **lst)
{
	t_list *second_node;
	t_list *third_node;
	t_list *last_node;

	if (!lst || !(*lst))
		return;
	if (!(*lst)->next)	// si un élément
		return;
	second_node = (*lst)->next;
	last_node = (*lst)->previous;
	if (second_node->next == *lst) // si 2 éléments
	{
		*lst = second_node;
		ft_printf("sa\n");
		return;
	}
	third_node = second_node->next;
	third_node->previous = *lst;
	(*lst)->next = third_node;
	second_node->next = *lst;
	second_node->previous = (*lst)->previous;
	(*lst)->previous = second_node;
	last_node->next = second_node; 
	*lst = second_node;
	ft_printf("sa\n");
}


/* Stack B */
void	ft_sb(t_list **lst)
{
	t_list *second_node;
	t_list *third_node;
	t_list *last_node;

	if (!lst || !(*lst))
		return;
	if (!(*lst)->next)
		return;
	second_node = (*lst)->next;
	last_node = (*lst)->previous;
	if (second_node->next == *lst)
	{
		*lst = second_node;
		ft_printf("sb\n");
		return;
	}
	third_node = second_node->next;
	third_node->previous = *lst;
	(*lst)->next = third_node;
	second_node->next = *lst;
	second_node->previous = (*lst)->previous;
	(*lst)->previous = second_node;
	last_node->next = second_node; 
	*lst = second_node;
	ft_printf("sb\n");
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}