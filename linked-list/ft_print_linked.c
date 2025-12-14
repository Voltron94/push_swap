#include "push_swap.h" 

void	ft_print_linked(t_list *lst)
{
    t_list *cursor;

    cursor = lst;
    if (!lst)
        return;
    ft_printf("linked content : %i \n", cursor->content);
    if (cursor->next)
        cursor = cursor->next;
    while (cursor != lst)
    {
        ft_printf("linked content : %i \n", cursor->content);
        cursor = cursor->next;
    }
    
}