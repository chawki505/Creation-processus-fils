#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


pid_t p;


void executerQ() {
  #define NB_ITERS 5
  int i;
  for ( i = 0; i < NB_ITERS; i++) {
    printf("i = %d\n",i );
    sleep(rand()%4);
  }
}


int main() {

  printf("je vais executer fork()\n");

  p=fork();

  if (p==0) {
    /* code fils*/
      printf("pid=%d\n",getpid());
      executerQ();
      printf("pid pere =%d\n",getppid());
      printf("fin du fils\n");
      exit(0);
  }

  if (p>0) {
    /* code pere */
      printf("pid=%d\n",getpid());
      sleep(30);
      printf("pid fis=%d\n",p);
      printf("fin du pere\n");
      exit(0);


  }
   if (p<0) {
     /* code echec*/
     printf("echec creation du fils" );
     exit(0);
   }



  return 0;
}
