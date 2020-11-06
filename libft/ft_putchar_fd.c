#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
    if (fd  != NULL)
    {
        write(fd, &c, 1);
    }
}