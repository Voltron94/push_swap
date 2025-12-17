#include "push_swap.h"

/*Echange les deux premier element de la list*/

/* Stack A */
void	ft_sa(t_list **lst)
{
    t_list *head;
    t_list *second_node;
    t_list *third_node;
	t_list *last_node;

	head = *lst;
	second_node = head->next;
	last_node = head->previous;
	if (!lst || !(*lst))
		return;
	if (!head->next)
	{
       	//ft_printf("error : can't swap a node with nothing\n");
    	return;	
	}
	else if (head->next->next == head)
	{
		*lst = second_node;
    }
	else 
	{
		third_node = second_node->next;
		third_node->previous = head;

		head->next = third_node;

		second_node->next = head;
		second_node->previous = head->previous;

		head->previous = second_node;

		last_node->next = second_node; 
		*lst = second_node;
		ft_printf("sa\n");
	}
}

/* Stack B */
void	ft_sb(t_list **lst)
{
    t_list *head;
    t_list *second_node;
    t_list *third_node;
	t_list *last_node;

	head = *lst;
	second_node = head->next;
	last_node = head->previous;
	if (!lst || !(*lst))
		return;
	if (!head->next)
    	return;	
	else if (head->next->next == head)
	{
		*lst = second_node;
    }
	else 
	{
		third_node = second_node->next;
		third_node->previous = head;

		head->next = third_node;

		second_node->next = head;
		second_node->previous = head->previous;

		head->previous = second_node;

		last_node->next = second_node; 
		*lst = second_node;
		ft_printf("sb\n");
	}
}


void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}