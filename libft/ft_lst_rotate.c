#include "libft.h"

void	ft_lst_rotate(t_list **lst)
{
    t_list *head;
    t_list *second_node;
    t_list *before_tail;
    t_list *tail;

    /*      Definition global    */
    head = *lst;
    second_node = head->next;
    tail = head->previous;      //definir l'actuelle queue de liste
    before_tail = tail->previous;   //garde temporairement le prev de tail pour le donner plus tard a la tete

    if (head->next == head->previous)
    {
        ft_printf("wtf ???\n");
        //definition tete
        tail->previous = head;
        tail->next = tail->previous;

        //queue
        head->next = tail;
        head->previous = tail;
    }
    else 
    {
        /*      Definir la nouvelle tete    */
    
        tail->next = second_node;    //garder la suite
        tail->previous = head;      //redefinir le previous de la queue pour se comporter comme la tete

        /*      Definir la nouvelle queue       */
        head->next = tail;       
        head->previous = before_tail;

        /*      Redefinir le previous de la seconde node    */
        second_node->previous = tail;
        /*      Redefinir le next avant la fin      */
        before_tail->next =  head;
    }
    *lst = tail;
}

/*
        Node1 -> Node2 
        p   n     p    n

    head-next = ;
    tail-previous = 
*/