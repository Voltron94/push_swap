#include "push_swap.h" 

void	ft_print_linked(t_list *lst)
{
    t_list *cursor;

    cursor = lst;
    while (cursor)
    {
        ft_printf("linked content : %i \n", cursor->content);
        cursor = cursor->next;
    }
}