#include "checker.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ns;
	int		i = 0;
	int		j = 0;

	ns = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ns)
		return (NULL);
    while (s1[i])
    {
        ns[i] = s1[i];
        i++;
    }
    while (s2[j])
        ns[i++] = s2[j++];
    ns[i] = '\0';

    return (ns);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*ns;
	int		i;
	int		str_size;

	i = 0;
	if (!s)
		return (NULL);
	str_size = ft_strlen(s);
	if (start >= str_size)
		return (ft_strdup(""));
	if (len + start > str_size)
		len = str_size - start;
	ns = malloc((len + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	while (i < len)
	{
		ns[i] = s[start + i];
		i++;
	}
	ns[len] = '\0';
	return (ns);
}

char	*ft_strdup(char *s)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
