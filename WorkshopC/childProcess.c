#include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void childProcess(){
    pid_t process = fork();
    if(process<0){
        perror("fork fail");
    }
    printf("Process ID %d\n", getpid());
    printf("Parent process ID %d\n", getppid());
    if (process == 0){
        exit(0);
    }
}

int main(){
    childProcess();
    return 0;
}
