#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int			content;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

#include <unistd.h>
#include <stdlib.h> //exit() compris
#include "ft_printf/ft_printf.h"

/* --- Linked List --- */

t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_print_linked(t_list *lst);

/* --- Utils --- */

int					ft_atoi(const char *nptr);


#endif