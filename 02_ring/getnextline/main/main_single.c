#include "../get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (void)
{
	char	*line;
	int		i = 0;
	ssize_t	fd1;
	ssize_t	fd2;
	ssize_t	fd3;
	char	file1[1024] = "./test/test.txt";
	char	file2[1024] = "./test/test2.txt";
	char	file3[1024] = "./test/test3.txt";

	printf("BUFFER_SIZE: %d\n----------------------\n", BUFFER_SIZE);
	fd1 = open(file1, O_RDONLY);
	if (fd1== -1)
	{
		printf("Caraculo!\n");
		return (0);
	}
	fd2 = open(file2, O_RDONLY);
	if (fd2== -1)
	{
		printf("Caraculo!\n");
		return (0);
	}
	fd3 = open(file3, O_RDONLY);
	if (fd3== -1)
	{
		printf("Caraculo!\n");
		return (0);
	}
	while (i++ <= 5)
	{
		line = get_next_line(fd1);
		printf("[fd1]: %s\n", line);
		free(line);
		line = get_next_line(fd2);
		printf("[fd2]: %s\n", line);
		free(line);
		line = get_next_line(fd3);
		printf("[fd3]: %s\n", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
