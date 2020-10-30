#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int ft_isalpha(int c);
int ft_isdigit(int c);

int ft_isalnum(int c)
{
	if (ft_isalpha(c) && ft_isdigit(c))
		return (1);
	return (0);
}

int main()
{
	int i;
	for (i = 0; i < 500; i++)
	{
		if (isalnum(i) != ft_isalnum(i))
			printf("%d", i);
	}
	return 0;
}
