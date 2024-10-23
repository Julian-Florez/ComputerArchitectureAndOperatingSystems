#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int execute(char *program) {
    char *args[] = {program, NULL};
    execvp(args[0], args);
    

    perror("execvp");
    return EXIT_FAILURE;
}

int main() {
    execute("/usr/bin/x-terminal-emulator");
    return 0;
}