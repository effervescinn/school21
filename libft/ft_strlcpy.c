#include "libft.h"
#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	//char *new_dst;
	const char *new_src;

	//new_dst = dst;
	new_src = src;
	while (*dst && *src && dstsize)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	*dst = '\0';
	return (ft_strlen(new_src));
}

int main()
{
	char dst[4] = "yyy";
	const char src[6] = "aaaaa";
	printf("%ld\n", ft_strlcpy(dst, src, 1));
	printf("%s", dst);
	return 0;
}
