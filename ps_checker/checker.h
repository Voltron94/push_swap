#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../push_swap.h"
# include <limits.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
int		n_check(char *stash);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s);

void	action(char *s, int size, t_list **stack_a, t_list **stack_b);

#endif