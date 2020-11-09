#include "libft.h"

static int is_equal(char c, char const *set)
{
	int set_len;
	int i;

	set_len = ft_strlen(set);
	i = 0;
	while (i < set_len)
	{
		if (c == set[i])
			return(1);
		i++;
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char *trim;
	long trim_len;
	char *start;
	int s1_len;
	int i;

	trim_len = 0;
	i = 0;
	s1_len = ft_strlen(s1);
	while (is_equal(s1[i], set))
		i++;
	start = (char*)&s1[i];
	i = s1_len - 1;
	while (is_equal(s1[i], set))
		i--;
	trim_len = &s1[i]- start + 1;
	if (trim_len <= 0)
		trim_len = 0;
	if ((trim = (char*)malloc(trim_len * sizeof(*s1) + 1)))
	{
		// if (trim_len == 0)
		// {
		// 	*trim = '\0';
		// 	return(trim);
		// }
		ft_strlcpy(trim, start, trim_len + 1);
		return(trim);
	}
	return (NULL);
}

// int main() {
// 	char const s1[] = "";
// 	char set[] = "cdsd";

// 	printf("%s\n", ft_strtrim(s1, set));
// 	return 0;
// }