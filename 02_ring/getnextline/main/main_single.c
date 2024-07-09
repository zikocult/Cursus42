#include "../get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (void)
{
	char	*line;
	int		i = 0;
	ssize_t	fd1;
	char	file1[1024] = "./test/test3.txt";

	printf("BUFFER_SIZE: %d\n----------------------\n", BUFFER_SIZE);
	fd1 = open(file1, O_RDONLY);
	if (fd1== -1)
	{
		printf("Caraculo!\n");
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
