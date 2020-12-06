#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*new_str;
	int		i;

	new_str = (char*)s;
	i = 0;
	while (n)
	{
		new_str[i] = '\0';
		i++;
		n--;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char			*new_s;
	unsigned char	new_c;

	new_s = (char*)s;
	new_c = (unsigned char)c;
	while (*new_s)
	{
		if (*new_s == new_c)
			return (new_s);
		new_s++;
	}
	if (*new_s == '\0' && new_c == '\0')
		return (new_s);
	return (NULL);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*new_dst;
	const unsigned char	*new_src;

	new_dst = (unsigned char*)dst;
	new_src = (const unsigned char*)src;
	if (new_dst == NULL && new_src == NULL)
		return (dst);
	if (src < dst)
	{
		while (len--)
			new_dst[len] = new_src[len];
	}
	else
	{
		while (len--)
		{
			*new_dst = *new_src;
			new_dst++;
			new_src++;
		}
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res_str;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if ((res_str = (char*)malloc((s1_len + s2_len) * sizeof(*s1) + 1)))
	{
		ft_bzero(res_str, ft_strlen(s1) + ft_strlen(s2) + 1);
		ft_memmove(res_str, s1, ft_strlen(s1));
		res_str = res_str + ft_strlen(s1);
		ft_memmove(res_str, s2, ft_strlen(s2));
		return (res_str - ft_strlen(s1));
	}
	return (NULL);
}

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

t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	if (!(newlist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (ft_strlen(s) <= start)
		len = 0;
	if (!(substr = (char *)malloc((len + 1) * sizeof(*s))))
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*new_dest;
	const char		*new_src;

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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*new_src;

	new_src = src;
	if (dst == NULL && src == NULL)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (*new_src && (dstsize - 1))
	{
		*dst = *new_src;
		dst++;
		new_src++;
		dstsize--;
	}
	*dst = '\0';
	return (ft_strlen(src));
}