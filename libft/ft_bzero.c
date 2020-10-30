#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    char			*new_str;
	int				i;

	new_str = (char*)s;
	i = 0;
	while (n)
	{
		new_str[i] = '\0';
		i++;
		n--;
	}
}