#include "libft.h"
#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*new_dst;
	const char	*new_src;
	size_t		dst_len;
	
	new_dst = dst;
	new_src = src;

	dst_len = ft_strlen(dst);
	new_dst = new_dst + dst_len;

	if (dstsize < ft_strlen(dst)) //<= ?
		return (ft_strlen(src) + dstsize);
	dstsize = dstsize - ft_strlen(dst) - 1;

	ft_memcpy(new_dst, new_src, dstsize);

	//dst[ft_strlen(dst)] = '\0'; // эээээээээээ, надо прочекать еще раз, но все работает
	return (dst_len + ft_strlen(src));
}


// int main (void)
// {
//   char a[25] = "1234";
//   char b[7] = "qwerty";
//   printf("%lu\n", strlcat(a, b, 4));
//   printf("%s\n", a);
// }
