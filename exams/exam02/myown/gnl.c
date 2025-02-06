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
	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	while (read(fd, &a[i], 1) == 1)
	{
		if (a[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	if (!a[0])
		return (NULL);
	new_s = malloc(i + 1);
	if (!new_s)
		return (NULL);
	i = 0;
	while (a[i])
	{
		new_s[i] = a[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
