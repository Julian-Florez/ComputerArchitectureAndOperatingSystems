#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {

        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {

        printf("Child process (PID: %d) is running.\n", getpid());

        sleep(2);
        printf("Child process (PID: %d) is done.\n", getpid());
        exit(0);
    } else {

        printf("Parent process (PID: %d) is waiting for child process (PID: %d) to finish.\n", getpid(), pid);
        wait(NULL); 
        printf("Parent process (PID: %d) detected that child process (PID: %d) has finished.\n", getpid(), pid);
    }

    return 0;
}