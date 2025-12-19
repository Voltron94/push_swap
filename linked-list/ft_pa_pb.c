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
    //prendre le cas stack b = 1
    if (!head_a->next) //si un seul element     //couper cette partit en 2 fonction : pa_one_element
    {
        ft_printf("condition atteint \n\n");
        /* head b beacome head a*/
        head_b->next = head_a;
        head_b->previous = head_a;
        /* fix the stack B */
        head_a->next = head_b;
        head_a->previous = head_b;
        b_second->previous = tail_b;
        tail_b->next = b_second;
        *stack_a = *stack_b;
        *stack_b = b_second;
        ft_printf("pb\n");
        return;
    }
    /* head b beacome head a*/
    head_b->next = head_a;
    head_b->previous = head_a->previous;

    head_a->previous = head_b;
    tail_a->next = head_b;

    /* fix the stack B */

    b_second->previous = tail_b;
    tail_b->next = b_second;

    /* end */
    *stack_a = *stack_b;
    *stack_b = b_second;
    ft_printf("pa\n");
}

void				ft_pb(t_list **stack_a, t_list **stack_b)
{
    t_list *head_a;
    t_list *head_b;
    t_list *tail_a;
    t_list *tail_b;
    t_list *a_second;

    if (!(*stack_b))
        return;
    head_a = *stack_a;
    head_b = *stack_b;
    tail_a = head_a->previous;
    tail_b = head_b->previous;
    a_second = head_a->next;
    //prendre le cas stack a = 1
    if (!head_b->next) //si un seul element     //couper cette partit en 2 fonction : pb_one_element
    {
        ft_printf("condition atteint \n\n");
        /* head a beacome head b */
        head_a->next = head_b;
        head_a->previous = head_b;
        /* fix the stack B */
        head_b->next = head_a;
        head_b->previous = head_a;
        a_second->previous = tail_b;
        tail_a->next = a_second;
        *stack_b = *stack_a;
        *stack_a = a_second;
        return;
    }
    /* head a beacome head b*/
    head_a->next = head_b;
    head_a->previous = head_b->previous;
    head_b->previous = head_a;
    tail_b->next = head_a;
    /* fix the stack a */
    a_second->previous = tail_a;
    tail_a->next = a_second;
    /* end */
    ft_printf("pb\n");
    *stack_b = *stack_a;
    *stack_a = a_second;
}


// void				ft_pb(t_list **stack_a, t_list **stack_b)
// {

// }
// The first element of B becomes the first of A
// and the second of B becomes the head of B