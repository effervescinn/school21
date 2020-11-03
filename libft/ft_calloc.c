#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
	void *ptr;

	if ((ptr = (void *)malloc(count * size)))
	{
		ft_bzero(ptr, count * size);
		return (ptr);
	}
	return (NULL);
}