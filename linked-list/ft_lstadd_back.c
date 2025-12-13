#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *cursor;
    t_list *tmp;

    cursor = *lst;
    if (cursor)
    {
        while (cursor->next) // != *lst
            cursor = cursor->next;
        new->previous = cursor;
        cursor->next = new;
    }
    else if (!cursor)
        *lst = new;
}

/*
    Exemple sans double pointer :

    void	ft_lstadd_back(t_list *lst, t_list *new)
    {
        t_list *cursor;

        cursor = lst;
        if (cursor)
        {
            while (cursor->next)
                cursor = cursor->next
            cursor->next = new;
        }
    }


    le double pointer va permettre de dereferencer *lst vers new
    le pointer lst va pointer vers une nouvelle adresse.
*/
