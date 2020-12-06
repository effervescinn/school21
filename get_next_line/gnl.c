#include "get_next_line.h"

char	*check_rest(char *rest, char **line)
{
	char *p;

	p = NULL;
	if (rest)
	{
		if ((p = strchr(rest, '\n')))
		{
			*p = '\0';
			*line = ft_strdup(rest);
			p++;
			ft_strlcpy(rest, p, ft_strlen(p));
		}
		else
		{
			*line = ft_strdup(rest);
			//ft_strlcr(rest);
		}
	}
	else
		*line = "";
	return (p);
}

int	get_next_line(int fd, char **line)
{
	static char *rest;
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	char		*p;
	//char		*tmp;

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
	return (0);
}

int main() {
	int fd;
	char *line;

	fd = open("test1.txt", O_RDWR);
	// while (get_next_line(fd, &line))
	// {
	// 	printf("%s", line);
	// }
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	//printf("%s", &line);
	return 0;
}