#include "push_swap.h"

void				ft_pa(t_list **stack_a, t_list **stack_b)
{
    t_list *head_a;
    t_list *head_b;
    t_list *tail_a;
    t_list *tail_b;
    t_list *b_second;

    if (!(*stack_b))
        return;
    head_a = *stack_a;
    head_b = *stack_b;
    tail_a = head_a->previous;
    tail_b = head_b->previous;
    b_second = head_b->next;
    
    /* head b beacome head a*/
    head_b->next = head_a;
    head_b->previous = head_a->previous;

    head_a->previous = head_b;
    tail_a->next = head_b;

    /* fix the stack B */

    b_second->previous = tail_b;
    tail_b->next = b_second;

    /* end */
    ft_printf("pa\n");
    *stack_a = *stack_b;
    *stack_b = b_second;
}

void				ft_pa(t_list **stack_a, t_list **stack_b)
{
    t_list *head_a;
    t_list *head_b;
    t_list *tail_a;
    t_list *tail_b;
    t_list *b_second;

    if (!(*stack_b))
        return;
    head_a = *stack_a;
    head_b = *stack_b;
    tail_a = head_a->previous;
    tail_b = head_b->previous;
    b_second = head_b->next;
    
    /* head b beacome head a*/
    head_b->next = head_a;
    head_b->previous = head_a->previous;

    head_a->previous = head_b;
    tail_a->next = head_b;

    /* fix the stack B */

    b_second->previous = tail_b;
    tail_b->next = b_second;

    /* end */
    ft_printf("pa\n");
    *stack_a = *stack_b;
    *stack_b = b_second;
}


// void				ft_pb(t_list **stack_a, t_list **stack_b)
// {

// }
// The first element of B becomes the first of A
// and the second of B becomes the head of B