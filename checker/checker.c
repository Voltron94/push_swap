#include "checker.h"

int	main(int argc, char **argv)
{
	char	*s;

	s = NULL;
	s = get_next_line(0);
	ft_printf("line %i : %s", 1, s);
	free(s);

	ft_printf("  completed  ");
	return (0);
}