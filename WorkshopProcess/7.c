#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {

  int i, j;
  pid_t pid, nuevo, nuevo1;
  time_t ini, fin;
  ini= time(NULL);

  for (i=0; i< 2; i++) {
    pid= getpid();
    for (j=0; j< 1+2; j++){
      nuevo= fork();
      if (nuevo== 0) {
        break;
        nuevo1= fork();
        if (nuevo1== 0)
          execlp ("xload", "xload", NULL);
      }
    }
    if (pid!= getpid())
      execlp ("kcale", "kcale", NULL);
  }

  for (i = 0; i<2; i++)
    for (j = 0; j< i+2; j++){
      wait(NULL);
      printf("Tiempo en ejecución de kcalc: %ld\n", time(NULL)-ini);
    }

  printf("Tiempo total: %ld\n", time(NULL)-ini);
  return 0;
}