#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list *current;
	t_list *tmp;

	if (!lst || !*lst)
		return ;
	current = *lst;
	tmp = *lst;
	if ((*lst)->previous)
		(*lst)->previous->next = NULL;
	while (current)
	{
		tmp = tmp->next;
		free(current);
		current = tmp;
	}
	*lst = NULL;
}