#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void pipeParentChild(char *message) {
    int pipefd[2];
    pid_t pid;
    char read_msg[100];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { 
        close(pipefd[0]); 
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]); 
    } else { 
        close(pipefd[1]);
        read(pipefd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(pipefd[0]); 
    }
}

int main() {
    pipeParentChild("Hello, World!");
    return 0;
}