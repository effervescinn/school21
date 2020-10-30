#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    char			*new_dest;
	const char      *new_src;

	new_dest = (char*)dest;
	new_src = (const char*)src;
	if (new_dest == NULL && new_src == NULL)
		return (dest);
	while (n)
	{
		*new_dest = *new_src;
		new_dest++;
		new_src++;
		n--;
	}
	return (dest);
}