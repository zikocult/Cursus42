#include <stdio.h>
#include <fcntl.h> //open() & close() 
#include <unistd.h> //dup2()

// La función dup2, permite cambiar una salida standard (stdin, stdout, stderr)
// a un fd abierto previamente, en este ejemplo, veremos que printf, no muestra
// nada en pantalla y lo envía todo a example.txt
 
int main()
{
	int fd;
 
	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	printf("This is printed in example.txt!\n");
 
	return (0);
}
