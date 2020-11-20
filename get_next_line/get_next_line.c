// return:
// 1 : A line has been read
// 0 : EOF has been reached
// -1 : An error happened
#include "get_next_line.h"

// 12345
// abc

void	get_line_and_rest(char *new_line, char *rest, char **line)
{
	int	i;

	i = 0;
	while (new_line[i] != '\n')
		i++;
	*line = ft_substr(new_line, 0, i);
	rest = ft_strdup(new_line + i + 1);
}

int get_next_line(int fd, char **line)
{
	//static int	fd_arr[1024];
	int 			ret;
	char			buf[BUFFER_SIZE + 1];
 	static char		*rest;
	char			*new_line;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			new_line = ft_strjoin(rest, buf);
			get_line_and_rest(new_line, rest, line);
			free(new_line);
		}
		*line = ft_strjoin(rest, buf);
	}
	return (1);
}

int main() {
	int fd;
	char **line;

	fd = open("test1.txt", O_RDWR);
	get_next_line(fd, line);
	return 0;
}