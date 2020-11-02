#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char *new_s;
	unsigned char new_c;
	size_t i;

	new_s = (unsigned char *)s;
	new_c = (unsigned char)c;
	i = ft_strlen((const char *)new_s);
	new_s = new_s + i;
	while (new_s >= (unsigned char *)s)
	{
		if (*new_s == new_c)
			return ((char *)new_s);
		new_s--;
	}
	return (NULL);
}
