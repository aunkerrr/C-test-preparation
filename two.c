#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#define THREADS_QUANTITY 3

void *thread_detached_identifier(void *arg) {
  int *argument = (int*) arg;

  for(int i = 0; i < 5; i++) {
    sleep(1);
    printf("Thread: My ID is [%d] my iteration number is [%d].\n", *argument, i);
  }
  printf("Thread: I'm finished my work and my id is %d.\n", *argument);
}


int main(int argv, char * argc[]) {
  pthread_attr_t pthread_attribute;
  pthread_t threads[THREADS_QUANTITY];

  pthread_attr_init(&pthread_attribute);
  pthread_attr_setdetachstate(&pthread_attribute, PTHREAD_CREATE_DETACHED);

  int threads_ids[THREADS_QUANTITY];

  for (int i = 0; i < THREADS_QUANTITY; i++)
  {
    threads_ids[i] = i;
    if(pthread_create(&threads[threads_ids[i]], &pthread_attribute, thread_detached_identifier, (void *) &threads_ids[i]) != 0){
      perror("Thread allocation failed");
      return EXIT_FAILURE;
    }
  }

  printf("Main: I'm finished my work.\n");
  pthread_attr_destroy(&pthread_attribute);
  
  pthread_exit(NULL);
}