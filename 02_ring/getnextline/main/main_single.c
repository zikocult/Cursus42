#include "../get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (void)
{
	char	*str_gnl;
	ssize_t	fd;
	int		i = 0;
	int		counter = 0;
	char	file[1024] = "../test/test2.txt";
	char	caracter;

	printf("BUFFER_SIZE: %d\n----------------------\n", BUFFER_SIZE);
	counter = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Caraculo!\n");
		return (0);
	}
	while (read(fd, &caracter, 1) == 1)
		if (caracter == '\n')
			counter++;
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Caraculo!");
		return (1);
	}
	while (i++ < counter)
	{
		str_gnl = get_next_line(fd);
		printf("%s\n", str_gnl);
	}
	close(fd);
	free(str_gnl);
	return (0);
}
