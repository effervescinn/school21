
#include <stdio.h>
#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    char			*new_dest;
	const char      *new_src;
	int				i;

	new_dest = (char*)dest;
	new_src = (const char*)src;
	i = 0;
	while (n && new_src[i] && new_dest[i])
	{
		new_dest[i] = new_src[i];
		i++;
		n--;
	}
	return (dest);
}
