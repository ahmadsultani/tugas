#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum;
void *runner(void *params);

int main(int argc, char * args[]) {
  pthread_t tid1, tid2;
  pthread_attr_t attr1, attr2;
  
  if(argc < 2) {
      fprintf(stderr,"Usage a.out <an integer value>\n");
      return -1;
  }

  if (atoi(args[1]) < 0) {
      fprintf(stderr,"%d must be >= 0\n",atoi(args[1]));
      return -1;
  }

  // printf("I am the %ld from main function\n",pthread_self());
  pthread_attr_init(&attr1);
  pthread_attr_init(&attr2);
  pthread_create(&tid1,&attr1,runner,args[1]);
  pthread_create(&tid2,&attr2,runner,args[1]);
  *runner(args[1]);
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
}

void *runner(void *params) {
    int i, upper = atoi(params);
    sum = 0;
    for(i=1;i<=upper;i++) {
       sum += i;
       printf("I am the %ld from runner = %d\n",pthread_self(), sum);
    }
    pthread_exit(0);
}