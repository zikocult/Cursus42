#include "../get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char **argv)
{
	char *line;
	ssize_t	*fd;
	int	i = 0;

	if (argc > 1)
	{
		i = 1;
		printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
		fd = (ssize_t *)malloc(argc - 1 * sizeof(ssize_t));
		if (!fd)
			return (0);
		while (i <= argc)
		{
			fd[i - 1] = open(argv[i], O_RDONLY);
			if (fd[i - 1] == -1)
			{
				printf("Caraculo!\n");
				free (fd);
				return (0);
			}
			i++;
		}
		i = 0;
		while (i < 10)
		{
			line = get_next_line(fd[i % 3]);
			printf("%s", line);
			free(line);
			i++;
		}
		i = 1;
		while (i <= argc)
		{
			close(fd[i - 1]);
			i++;
		}
	}	
	else
		printf("Faltan argumentos para seguir\n");
	free (fd);
	return (0);
}
