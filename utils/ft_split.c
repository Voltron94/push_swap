#include <stdio.h>
#include <stdlib.h>

static int count_word(const char *s, char ch)
{
    int i;
    int c;
    int in_word;

    in_word = 0;
    i = 0;
    c = 0;
    while (s[i])
    {
        if (in_word == 0 && s[i] != ch)
        {
            in_word = 1;
            c++; //hehe
        }
        else if (in_word == 1 && s[i] == ch)
        {
            in_word = 0;
        }
        i++;
    }
    // printf("count word : %i\n", c);
    return (c);
}

static void ft_strlcpy(char *ns, const char *s, int len)
{
    int i;

    i = 0;
    while (i < len - 1)
    {
        ns[i] = s[i];
        i++;
    }
    ns[i] = '\0';
}

static void claim_word(char **ns, const char *s, char lim)
{
    int i;
    int len;

    i = 0;
    while (*s)
    {
        len = 0;
        while (*s == lim && *s)
            s++;
        while (*s != lim && *s)
        {
            len++;
            s++;
        }
        if(len)
        {
            ns[i] = malloc(len * sizeof(char));
            ft_strlcpy(ns[i], s - len, len + 1);
            i++;
        }

    }
    ns[i] = NULL;
}

char	**ft_split(const char *s, char c)
{
    char **ns;

    ns = malloc(count_word(s, c) * sizeof(char *));
    if (!ns)
        return NULL;
    claim_word(ns, s, c);
    return (ns);
}

// int main()
// {
//     char *s = "SalutOOOOCommentOvOaOtuOOOO?";
//     char **ns = ft_split(s, 'O');

    // for (int i = 0;  ns[i]; i++)
    // {
    //     printf("ns : %s \n", ns[i]);
    // }
// }