#include "libft.h"

int	ft_arg_len(char **s)
{
	int i = 0;
	while (s[i])
        i++;
    return (i);
}