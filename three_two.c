#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define THREAD_QUANTITY 4
#define INCREMENTS 500000
#define RESULT_EXPECTED THREAD_QUANTITY * INCREMENTS

pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
unsigned long int counter = 0;

void *incrementor(void* args) {

  for(int i = 0; i < INCREMENTS; i++) {
    counter++;
  }

  return NULL;
}

int main(int argv, char *argc) {
  pthread_t counting_threads[THREAD_QUANTITY];

  for (int i = 0; i < THREAD_QUANTITY; i++) {
    if(pthread_create(&counting_threads[i], NULL, *incrementor, NULL)  != 0) {
      perror("Thread allocation ERROR");
      return EXIT_FAILURE;
    }
  }
  

  for (int i = 0; i < THREAD_QUANTITY; i++) {
    pthread_join(counting_threads[i], NULL);
 
  }

  printf("Main thread: Expected result is [%lu], Real result is [%lu] ", RESULT_EXPECTED, counter);

  return EXIT_SUCCESS;
}