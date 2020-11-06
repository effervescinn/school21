#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
    if (fd != NULL)
    {
        while (*s)
        {
            write(fd, s, 1);
            s++;
        }
        *s = '\n';
    }
}