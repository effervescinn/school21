#include "get_next_line.h"

int check_rest(char **rest, char **line)
{
	char *p;

	if (*rest)
	{
		if ((p = ft_strchr(*rest, '\n')))
		{
			*p = '\0';
			*line = ft_strdup(*rest);
			p++;
			free(*rest);
			ft_strcpy(*rest, p);
			return (0);
		}
		else
		{
			*line = ft_strdup(*rest);
			//free(*rest);
			*rest = NULL;
		}
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char *rest;
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	char		*p;
	char		*tmp;
	int			c_r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	*line = (char*)malloc(sizeof(char));
	**line = '\0';
	c_r = check_rest(&rest, line);
	while (c_r && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		if ((p = ft_strchr(buf, '\n')))
		{
			*p = '\0';
			p++;
			rest = ft_strdup(p);
			tmp = *line;
			*line = ft_strjoin(tmp, buf);
			free(tmp);
			return (1);
		}
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && rest == NULL)
		return (0);
	return (1);
}

int main() {
	int fd;
	char *line;

	fd = open("test1.txt", O_RDWR);
	while (get_next_line(fd, &line) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
	printf("%s\n", line);
	free(line);
	getc(stdin);
}