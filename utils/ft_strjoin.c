#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ns;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ns = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!ns)
		return (NULL);
	while (s1[i])
	{
		ns[i] = s1[i];
		i++;
	}
	while (s2[j])
		ns[i++] = s2[j++];
	ns[i] = ' ';
	ns[i + 1] = '\0';
	return (ns);
}