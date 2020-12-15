#include "get_next_line.h"

int check_rest(char **rest, char **line)
{
	char *p;

	if (*rest)
	{
		free(*line);
		if ((p = ft_strchr(*rest, '\n')))
		{
			*p = '\0';
			if (!(*line = ft_strdup(*rest)))
				return (-1);
			p++;
			ft_strcpy(*rest, p);
			return (0);
		}
		else
		{
			if (!(*line = ft_strdup(*rest)))
				return (-1);
			free(*rest);
			*rest = NULL;
		}
	}
		return (1);
}

int	get_next_line(int fd, char **line)
{
	static char *rest[1024];
	char		*buf;
	int			ret;
	char		*p;
	char		*tmp;
	int			c_r;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || fd > 1023 ||
	(read(fd, NULL, 0)) == -1)
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char))))
		return (-1);
	**line = '\0';
	c_r = check_rest(&rest[fd], line);
	if(!(buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char))) || c_r < 0)
		return (-1);
	while (c_r > 0 && (ret = read(fd, buf, BUFFER_SIZE > 0)))
	{
		buf[ret] = '\0';
		if ((p = ft_strchr(buf, '\n')))
		{
			*p = '\0';
			p++;
			if (!(rest[fd] = ft_strdup(p)))
				return (-1);
			c_r = 0;
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)))
			{
				free(tmp);
				return (-1);
			}
		free(tmp);
	}
	free(buf);
	if (ret < 0 || c_r < 0)
		return (-1);
	return ((ret == 0 && rest[fd] == NULL) ? 0 : 1);
}

// int main() {
// 	int fd;
// 	int fd2;
// 	char *line;

// 	fd = open("test1.txt", O_RDWR);
// 	fd2 = open("test2.txt", O_RDWR);
// 	while (get_next_line(fd, &line) > 0)
// 		{
// 			printf("%s\n", line);
// 			free(line);
// 		}
// 	printf("%s", line);
// 	free(line);
// 	get_next_line(fd2, &line);
// 	printf("%s\n", line);
// 	//getc(stdin);
// }