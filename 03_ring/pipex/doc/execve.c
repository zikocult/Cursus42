#include <unistd.h> //execve()
#include <stdio.h>
 
int main()
{
	char *args[3];
 
	args[0] = "ls"; //no se usa en la linea de comandos, sirve para saber que comando usaremos
	args[1] = "-l";
	args[2] = NULL;
	execve("/bin/ls", args, NULL);
	printf("This line will not be executed.\n");
 
	return (0);
}
