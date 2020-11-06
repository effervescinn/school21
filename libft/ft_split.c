#include "libft.h"

static int count_c(char const *s, char c)
{
	int c_q;

	c_q = 0;
	while (*s)
	{
		while (*s != c)
			s++;
		if (*s == c)
		{
			while (*s == c)
				s++;
			c_q++;
		}
		s++;
	}
	return (c_q);
}

static int	*count_item_len(char const *s, char c, int *item_len)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			s++;
			len++;
		}
		item_len[i] = len;
		len = 0;
		i++;
	}
	return (item_len);
}

// char	**ft_split(char const *s, char c)
// {
// 	char **arr;
// 	int i;
// 	int j;
// 	int *item_len;

// 	i = 0;
// 	j = 0;
// 	if ((arr = (char **)malloc(count_c(s, c) * sizeof(char*) + 2 * sizeof(char*))))
// 	{
// 		item_len = (int*)malloc(count_c(s, c) * sizeof(int) + sizeof(int))

// 		while (*s)
// 		{

// 		}
// 	}
// }

int main()
{
	int arr[3];
	
	int i;
	count_item_len("yyfgdfgdfghyyyldyyy", 'y', arr);
	for (i = 0; i < 3; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}