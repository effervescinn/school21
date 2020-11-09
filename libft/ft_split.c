#include "libft.h"
#include <string.h>

static int count_words(char const *s, char c) //считаем количество слов
{
	int w_q;

	w_q = 0;
	while (*s)
	{
		while (*s == c)
		{
			s++;
			if (*s == '\0')
				return (w_q);
		}
		while (*s != c)
		{
			s++;
			if (*s == '\0')
				return (++w_q);
		}
		w_q++;
		s++;
	}
	return (w_q);
}

static void push_strs(const char *s, char c, char **arr, int w_q) //записываем строки в массив
{
	char *w_start;
	int w_len;

	while (*s && w_q--)
	{
		w_len = 0;
		while (*s == c && *s)
			s++;
		if (*s)
			w_start = (char *)s;
		while (*s != c && *s)
		{
			w_len++;
			s++;
		}
		if ((*arr = (char *)malloc(w_len * sizeof(char) + sizeof(char))))
		{
			ft_strlcpy(*arr, w_start, w_len + 1);
			arr++;
		}
	}
	*arr = NULL;
}

char **ft_split(char const *s, char c)
{
	char **arr;
	int w_q;

	w_q = count_words(s, c); //считаем количество слов чтобы выделить нужое количество памяти

	if ((arr = (char **)malloc(w_q * sizeof(char *) + sizeof(char *))))
	{
		push_strs(s, c, arr, w_q);
		return (arr);
	}
	return (NULL);
}
