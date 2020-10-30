#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
	char	*new_str;
	unsigned char 	s;
	int				i;

	new_str = (char*)b;
	s = (unsigned char)c;
	i = 0;
	while (len)
	{
		new_str[i] = s;
		i++;
		len--;
	}
	return (b);
}
