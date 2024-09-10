[**Results in this milestone**](https://github.com/zikocult/Cursus42/tree/main/02_ring)



This has been an exciting project. Initially, it seemed like a simple project, but far from reality, this was a project where memory leaks and handling malloc became critical.

Essentially, this project aims to delve into the use of static variables and line-by-line file reading, regardless of the number of characters we read as input.

The bonus task required us to implement a feature where we could read multiple files simultaneously using multiple threads.

**How to use it ✒️**

For this project, we were not allowed to create a makefile, so in order to use it, multiple test mains and different text files have been used for testing purposes. 

I've show the code of the main I used for compilation below. This compilation has always been done with the following flags and options:

* `-Wall` - Enable all compiler warnings
* `-Wextra` - Enable extra compiler warnings
* `-Werror` - Treat warnings as errors
* `-D BUFFER_SIZE=x` - Size allowed to read for every loop, x is a value.

Here is my main, i use arguments to simplify the tests.

```c
#include "../get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char **argv)
{
	char *line;
	ssize_t	fd;
	int	i = 0;
	int counter = 0;
	char caracter;

	if (argc > 1)
	{
		i = 0;
		printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
		counter = 0;
// count the number of lines the file has
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Openning fail!\n");
			return (0);
		}
		while (read(fd, &caracter, 1) == 1)
			if (caracter == '\n')
				counter++;
		close(fd);

// second open, here the execution starts
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Openning fail!");
			return (1);
		}
		while (i < counter)
		{
			line = get_next_line(fd);
			printf("%s", line);
			free(line);
			i++;
		}
		close(fd);
	}	
	else
		printf("No args to continue\n");
	return (0);
}
```

**My opinion about the project 📝**

This has been by far the most challenging project I have undertaken at 42Barcelona so far, and it was short, but there are many points where errors can arise, and they have indeed arisen during the coding process.

All this, apart from teaching me a lot about memory management, has led me to learn how to effectively use debuggers. In my case, I chose GDB (GNU Debugger) as my tool of choice, but I tried LLDB and DAP too.

In my opinion this is a 10/10 project to learn how to program in C.
