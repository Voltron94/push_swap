#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "../push_swap.h"

/* Utils */

int	    ft_strlen(char *str);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr, t_list **stack_a, t_list **stack_b);
int		ft_arg_len(char **av);

/* linked base */

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
void	ft_lst_rotate(t_list **lst);


#endif