#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define L1 2
#define L2 3

int main (int argc, char *argv[]){
    int cont1, cont2;
    pid_t pid;

    for (cont2= 0; cont2 < L2; cont2++){
        for (cont1= 0; cont1 < L1; cont1++){
            pid = fork();
            if (pid == 0){
              break;
            }
        }
        if (pid != 0){
            break;
        }
        printf("Soy el proceso %d y mi padre es %d\n", getpid(), getppid());
    }
    if (pid != 0){
        for (cont1= 0; cont1 < L1 + L2; cont1++){
            pid = wait(NULL);
            printf("Acaba de finalizar mi hijo con PID %d\n", pid);
        }
        printf("Mi PID es %d y he terminado\n", getpid());
    }
    return 0;
}