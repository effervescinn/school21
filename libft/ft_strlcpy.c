#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char *new_dst;
	const char *new_src;

	new_dst = dst;
	new_src = src;
	if (dst == NULL && src == NULL)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (*dst && *new_src && (dstsize - 1))
	{
		*dst = *new_src;
		dst++;
		new_src++;
		dstsize--;
	}
	*dst = '\0';
	return (ft_strlen(src));
}
