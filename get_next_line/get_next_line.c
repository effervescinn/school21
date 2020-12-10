#include "get_next_line.h"

char	*check_rest(char *rest, char **line)
{
	char *p;

	p = NULL;
	if (rest)
	{
		if ((p = ft_strchr(rest, '\n')))
		{
			*p = '\0';
			*line = ft_strdup(rest);
			p++;
			ft_strcpy(rest, p);
			//rest += ft_strlen(rest) + 1;
		}
		else
		{
			*line = ft_strdup(rest);
			// free(rest);
			// rest = NULL;
		}
	}
	else
	{
		*line = (char*)malloc(sizeof(char));
		**line = '\0';
	}
	return (p);
}

int	get_next_line(int fd, char **line)
{
	static char *rest;
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	char		*p;
	//char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (-1);
	p = check_rest(rest, line);
	while (!p && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		if ((p = ft_strchr(buf, '\n')))
		{
			*p = '\0';
			p++;
			rest = ft_strdup(p);
		}
		//tmp = *line;
		*line = ft_strjoin(*line, buf);
		//free(tmp);
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && **line == '\0')
	{
		free(*line);
		return (0);
	}
	return (1);
}

int main() {
	int fd;
	char *line;
	//char *rest = "bb\0ccc\nddd\0";
	// char *p; p = &(rest[3]);
	//ft_strcpy(rest, p);
	// rest += ft_strlen(rest) + 1;
	// printf("%s", rest);
	fd = open("test1.txt", O_RDWR);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
	}
	return 0;
}