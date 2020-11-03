#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	if ((ptr = (char *)malloc(ft_strlen(s1) * sizeof(*s1) + sizeof(*s1))))
	{
		ft_memcpy(ptr, s1, ft_strlen(s1));
		*(ptr + ft_strlen(s1)) = '\0';
		return (ptr);
	}
	return (NULL);
}
