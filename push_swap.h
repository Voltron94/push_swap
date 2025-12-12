#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}					t_list;

#include <unistd.h>
#include <stdlib.h> //exit() compris
#include <stdio.h>

/* --- Linked List --- */

t_list				*ft_lstnew(int content);

/* --- Utils --- */

int	ft_atoi(const char *nptr);


#endif