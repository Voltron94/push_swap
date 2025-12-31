#include "checker.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*s;

	fd = open("empty.txt", O_RDONLY);
	s = NULL;
	// printf("Entrer nouvelle Ligne \n\n");
	s = get_next_line(fd);
	printf("line %i : %s", 1, s);
	free(s);

	printf("  completed  ");
	close(fd);
	return (0);
}