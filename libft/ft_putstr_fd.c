#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
	if (fd)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}