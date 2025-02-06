#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *get_next_line(int fd)
{
	char a[999999] = {0};
	char *new_s;
	int i = 0;
	int j = 0;
	int bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((bytes_read = read(fd, &a[i], 1)) == 1)
	{
		if (a[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	if (bytes_read == -1 || (bytes_read == 0 && i == 0))
		return NULL;
	new_s = malloc(i + 1);
	while (j < i)
	{
		new_s[j] = a[j];
		j++;
	}
	new_s[j] = '\0';
	return (new_s);
}

/* int main (void) */
/* { */
/* 	char	*line; */
/* 	int		i = 0; */
/* 	ssize_t	fd1; */
/* 	char	file1[1024] = "./test3.txt"; */

/* 	printf("BUFFER_SIZE: %d\n----------------------\n", BUFFER_SIZE); */
/* 	fd1 = open(file1, O_RDONLY); */
/* 	if (fd1== -1) */
/* 	{ */
/* 		printf("Fail!\n"); */
/* 		return (0); */
/* 	} */
/* 	while (i <= 12) */
/* 	{ */
/* 		line = get_next_line(fd1); */
/* 		printf("[fd1]: %s\n", line); */
/* 		free(line); */
/* 		i++; */
/* 	} */
/* 	close(fd1); */
/* 	return (0); */
/* } */
