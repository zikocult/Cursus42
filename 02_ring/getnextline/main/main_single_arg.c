#include "../get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char **argv)
{
	char *str_gnl;
	ssize_t	fd;
	int	i = 0;
	int counter = 0;
	char caracter;

	if (argc > 1)
	{
		i = 0;
		printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
		counter = 0;
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Caraculo!\n");
			return (0);
		}
		while (read(fd, &caracter, 1) == 1)
			if (caracter == '\n')
				counter++;
		close(fd);
		fd = open(argv[1], O_RDONLY);
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
	}	
	else
		printf("Faltan argumentos para seguir\n");
	return (0);
}

