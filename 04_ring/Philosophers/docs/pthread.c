#include <stdio.h>
#include <pthread.h>

void *computation(void *add)
{
	long sum = 0;
	long *add_num = (long *)add;
	for (long i = 0; i < 1000000000; i++)
		sum += *add_num;
	printf("Add: %ld\n", sum);
	return (NULL);
}

int main(void)
{
	long value1 = 1;
	long value2 = 2;
	long value3 = 3;

	// Variables propies de pthread.h
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;

	// Els temps de dos funcions separades es proper al doble de temps
	// computation((void*) &value1);
	// computation((void*) &value2);
	// computation((void*) &value3);

	pthread_create(&thread1, NULL, computation, (void*) &value1);
	pthread_create(&thread2, NULL, computation, (void*) &value2);
	pthread_create(&thread3, NULL, computation, (void*) &value3);
	// Si fessim els joins abans de crear els thread, obtindriem el mateix temps que fent dos funcions separades
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	return (0);
}
