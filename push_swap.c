#include "push_swap.h"

int	argv_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void argv_node(int argc, char **argv, t_list *a)
{
    while
}

int	main(int argc, char **argv)
{
	t_list *a;
    t_list *b;
	int i;

	i = 1;
	a = NULL;
    b = NULL;
	if (argc == 1)  //aucun argument
		return (0);
	while (i < argc)
	{
		if (!argv_check(argv[i]))
			return (write(1, "error", 5));
		i++;
	}
	a = ft_lstnew(ft_atoi(argv[1]));
    argv_node(argc, argv, a);
	printf("%d", a->content);
}