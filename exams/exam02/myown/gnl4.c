#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *get_next_line(int fd) 
{
	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, NULL, 0) < 0) { return (NULL); }
	char *line = malloc(100000), *buf = line;
	while (read(fd, buf, 1) > 0 && *buf++ != '\n');
	return (buf > line) ? (*buf = 0, line) : (free(line), NULL);
}

int main (void)
{
	char	*line;
	int		i = 0;
	ssize_t	fd1;
	char	file1[1024] = "./testGNL/test3.txt";

	printf("BUFFER_SIZE: %d\n----------------------\n", BUFFER_SIZE);
	fd1 = open(file1, O_RDONLY);
	if (fd1== -1)
	{
		printf("Fail!\n");
		return (0);
	}
	while (i <= 12)
	{
		line = get_next_line(fd1);
		printf("[fd1]: %s\n", line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}


