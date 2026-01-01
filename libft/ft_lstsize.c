#include "libft.h"

int	ft_lstsize(t_list *lst)
{
    t_list *cursor;
	int		l;

	l = 0;
    cursor = lst;
    if (cursor->next != NULL)
    {
		l++;
		cursor = cursor->next;
	}
	while (cursor != lst)
	{
		l++;
		cursor = cursor->next;
	}
	return (l);
}