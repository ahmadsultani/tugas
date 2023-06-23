// Ahmad Sultani Dayanullah
// D121211080 

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

typedef struct {
  int start, end;
} Range;

int sum = 0;
int A[SIZE];

void *runner(void *params);

int main() {
  pthread_t tid1, tid2;
  pthread_attr_t attr1, attr2;

  // mengisi data A dengan bil. 1 - 1000
  for (int i = 1; i <= SIZE; i++) {
    A[i-1] = i;
  }

  Range range1 = {0, SIZE/2 - 1}; 
  Range range2 = {SIZE/2, SIZE - 1};

  pthread_attr_init(&attr1);
  pthread_attr_init(&attr2);
  
  pthread_create(&tid1, &attr1, runner, &range1);
  pthread_create(&tid2, &attr2, runner, &range2);

  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);

  printf("\nThe sum of data in A is %d\n", sum);

  int ansTest = SIZE * (1 + SIZE) / 2;
  printf("Sum with number theory's equation: %d\n\n", ansTest);

  if (sum == ansTest) {
    printf("Our sum is correct!\n");
  } else {
    printf("The sum is incorrect!\n");
  }

  return 0;
}

void *runner(void *params) {
  Range *range = (Range *) params;

  for(int i = range->start; i <= range->end ; i++) {
    sum += A[i];
    printf("I am %ld: added %d, current sum = %d\n", pthread_self(), A[i], sum);
  }

  pthread_exit(0);
}