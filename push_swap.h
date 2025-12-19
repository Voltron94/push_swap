#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*previous;
}					t_list;

# include "ft_printf/ft_printf.h"
# include <stdlib.h> //exit() compris
# include <unistd.h>

/* --- Linked Base--- */

t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_print_linked(t_list *lst);
void				ft_lst_rotate(t_list **lst);
void				ft_pa(t_list **stack_a, t_list **stack_b);
void				ft_pb(t_list **stack_a, t_list **stack_b);

/* --- Linked instruction --- */

void				ft_sa(t_list **lst);
void				ft_sb(t_list **lst);
void				ft_ss(t_list **stack_a, t_list **stack_b);

/* --- Utils --- */

int					ft_atoi(const char *nptr);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strlen(char *str);
char				*ft_strdup(char *s);
char				**ft_split(const char *s, char c);
int					ft_arg_len(char **s);

#endif