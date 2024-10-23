#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void filePermission(char *path, char *name, char *permissions) {

    char fullPath[1024];
    strcpy(fullPath, path);
    strcat(fullPath, name);
    int fd;

    mode_t p = (permissions == "RW") ? (S_IRUSR | S_IWUSR) : (permissions == "R") ? S_IRUSR : (permissions == "W") ? S_IWUSR : 0;

    fd = open(fullPath, O_CREAT | O_WRONLY, p);
    if (fd == -1) {
        perror("Error creating file");
    }

    close(fd);

    printf("File '%s' created with %s for the owner.\n", fullPath, permissions);
}

int main() {
    filePermission("./outFiles/", "example.txt", "RW");
    filePermission("./outFiles/", "example2.txt", "W");
    filePermission(".outFiles/", "example3.txt", "R");
    filePermission("./outFiles/", "example4.txt", "W");
    return 0;
}