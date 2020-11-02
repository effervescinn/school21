#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int is_space(const char s)
{
	if (s == ' ' || s == '\n' || s == '\t' || s == '\v' || s == '\f' || s == '\r')
		return (1);
	return (0);
}

static int is_num(const char s)
{
	if (s >= '0' && s <= '9')
		return (1);
	return (0);
}

int ft_atoi(const char *str)
{
	unsigned long long int res;
	int sign;

	res = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (is_num(*str))
	{
		res = res * 10 + *str - '0';
		str++;
	}
	if (res > 999999999999999999 && sign == 1)
		return (-1);
	if (res > 999999999999999999 && sign == -1)
		return (0);
	return (res * sign);
}
