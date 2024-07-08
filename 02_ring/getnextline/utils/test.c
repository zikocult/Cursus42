#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char **str;

	str = (char **)malloc(2 * sizeof(char *));
	str[0] = (char *)malloc(10);
	str[1] = (char *)malloc(10);

	strcpy(str[0], "Hello");
	strcpy(str[1], "Bye");
	printf("str[0] antes del free %s\n", str[0]);
	free(str[0]);
	str++;
	str[1] = (char *)malloc(10);
	strcpy(str[1], "Holi");
	printf("str[0] después del free %s\n", str[0]);
	printf("str[1] después del free %s\n", str[1]);
	strcpy(str[0], str[1]);
	printf("str[1] después del free y un nuevo strcpy %s\n", str[1]);
	free(str[0]);
	free(str[1]);
	free(str);
	return 0;
}
