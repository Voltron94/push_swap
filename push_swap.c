#include "push_swap.h"

int	argv_check(char *s)
{
	int	i;

	i = 0;
    while (s[i])
    {
        if (s[i] <= 58 && s[i] >= 48)
            return (1);
        i++;
    }
    return (0);
}

int	main(int argc, char **argv)
{
	int i;

    i = 0;
	while (i < argc - 1)
    {
        if (!argv_check(argv[i + 1]))
            return (write(1, "error", 5));
        i++;
    }
}