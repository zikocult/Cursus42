#include <stdio.h>
#include <unistd.h> //access()
 
int main()
{
	if (access("example.txt", R_OK) != -1)
		printf("I have permission\n");
	else
		printf("I don't have permission\n");
 
	return (0);
}
