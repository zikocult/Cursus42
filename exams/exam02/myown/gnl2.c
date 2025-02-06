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
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    while ((bytes_read = read(fd, &a[i], 1)) == 1)
    {
        if (a[i] == '\n')
        {
            i++;
            break;
        }
        i++;
    }

    if (bytes_read == -1 || (bytes_read == 0 && i == 0))
        return (NULL);

    new_s = malloc(i + 1);
    if (!new_s)
        return (NULL);

    for (int j = 0; j < i; j++)
        new_s[j] = a[j];
    new_s[i] = '\0';

    return (new_s);
}

