#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define fin 10000

void *counter(void *args){
  unsigned long int local_counter = 0;

  for (size_t i = 1; i < fin; i++) {
    local_counter = local_counter + (i * i);
  }

  unsigned long int *answer = malloc(sizeof(unsigned long int)); 

  *answer = local_counter;
  
  return (void*) answer;
}

int main(int argv, char* argc[]) {
  pthread_t thread;
  void * retval;

  pthread_create(&thread, NULL, *counter, NULL);

  unsigned long int expected = 0;

  for (int k = 1; k <= fin; k++) {
    expected = expected + (k * k);
  }

  pthread_join(thread, &retval);

  unsigned long int *casted_retval = (unsigned long int *) retval; 

  printf("Main: Value counted in thread is: %ld. Value calculated in main is %ld.\n", *casted_retval, expected);

  free(retval);
  return EXIT_SUCCESS;
}