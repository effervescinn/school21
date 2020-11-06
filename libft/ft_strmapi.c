#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char            *new_s;
    size_t          s_len;
    unsigned int    i;

    s_len = ft_strlen(s);
    i = 0;
    if ((new_s = (char*)malloc(s_len * sizeof(*s) + 1)))
    {
        while (i < s_len)
        {
            new_s[i] = f(i, s[i]);
            i++;
        }
        new_s[i] = '/0';
        return (new_s);
    }
    return (NULL);
}