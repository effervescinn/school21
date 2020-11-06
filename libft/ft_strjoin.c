#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res_str;

	if ((res_str = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) * sizeof(s1) + sizeof(s1)))))
	{
		ft_bzero(res_str, ft_strlen(s1) + ft_strlen(s2) + 1);
		ft_memmove(res_str, s1, ft_strlen(s1));
		res_str = res_str + ft_strlen(s1);
		ft_memmove(res_str, s2, ft_strlen(s2));
		return (res_str - ft_strlen(s1));
	}
	return (NULL);
}
