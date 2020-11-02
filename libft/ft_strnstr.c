#include "libft.h"
#include <string.h>
#include <stdio.h>

// size_t	ft_strlen(const char *str)
// {
// 	size_t i;

// 	i = 0;
// 	while (*str)
// 	{
// 		i++;
// 		str++;
// 	}
// 	return (i);
// }

// int ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	unsigned const char *new_s1;
// 	unsigned const char *new_s2;

// 	new_s1 = (unsigned const char*)s1;
// 	new_s2 = (unsigned const char*)s2;
// 	while (*new_s1 != '\0' && *new_s2 != '\0' && *new_s1 == *new_s2 && n > 1)
// 	{
// 		new_s1++;
// 		new_s2++;
// 		n--;
// 	}
// 	if (*new_s1 == *new_s2)
// 		return (0);
// 	else
// 		return (*new_s1 - *new_s2);
// }

// char *ft_strchr(const char *s, int c)
// {
// 	char 				*new_s;
// 	unsigned char 		new_c;

// 	new_s = (char*)s;
// 	new_c = (unsigned char)c;
// 	while (*new_s)
// 	{
// 		if (*new_s == new_c)
// 			return(new_s);
// 		new_s++;
// 	}
// 	if (*new_s == '\0' && new_c == '\0')
// 		return (new_s);
// 	return (NULL);
// }

// char	*ft_strcpy(char *dest, char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		dest[i] = str[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// char *ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	const unsigned char *n_haystack;
// 	const unsigned char *n_needle;
// 	size_t				needle_len;
// 	size_t				len_dif;

// 	n_haystack = (const unsigned char*)haystack;
// 	n_needle = (const unsigned char*)needle;
// 	needle_len = ft_strlen(n_needle);



// 	if (len == 0)
// 		return (NULL);
// 	if (n_haystack == '\0')
// 		return (NULL);
// 	if (n_needle == '\0')
// 		return ((char*)n_needle);
// 	if (needle_len > ft_strlen(n_haystack))
// 		return (NULL);

// 	len_dif = len - needle_len;
// 	while (len_dif--)
// 	{
// 		if (ft_strncmp(n_haystack, n_needle, needle_len) != 0)
// 			n_haystack++;
// 		else
// 			return ((char*)n_haystack);
// 	}
// 	return (NULL);
// }

// int main()
// {
// 	printf("%s\n", strnstr("fgh", "", 7));
// 	printf("%s\n", ft_strnstr("dfg", "", 7));
// 	return 0;
// }
