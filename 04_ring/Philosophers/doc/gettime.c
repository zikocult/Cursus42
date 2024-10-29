#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main() {

  struct timeval start, end;

  if (gettimeofday(&start, NULL) == -1)
    return (0);
  for (int i = 0; i < 1000000; i++) {
    // Do something
  }
  // usleep també congela el temps que conta gettimeofday
  usleep(5000000);
  if (gettimeofday(&end, NULL) == -1)
    return (0);
  printf("End.tv_sec %ld - Start.tv_sec %ld = %ld\n", end.tv_sec, start.tv_sec,
         end.tv_sec - start.tv_sec);
  printf("End.tv_usec %ld - Start.tv_usec %ld = %ld\n", end.tv_usec,
         start.tv_usec, end.tv_usec - start.tv_usec);
  printf("Elapsed: %ld microseconds\n",
         (end.tv_sec * 1000000 + end.tv_usec) -
             (start.tv_sec * 1000000 + start.tv_usec));
  return 0;
}
