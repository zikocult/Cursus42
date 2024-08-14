#include <stdio.h>
#include <stdlib.h> //perror
#include <unistd.h> //getpid() & fork() & exit
 
int main()
{
	pid_t pid;
 
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	printf("Quiero ver el pid: %i\n", pid);
 
	if (pid == 0)
		printf("This is the child process. (pid: %d)\n", getpid());
	else
		printf("This is the parent process. (pid: %d)\n", getpid());
 
	return (0);
}
