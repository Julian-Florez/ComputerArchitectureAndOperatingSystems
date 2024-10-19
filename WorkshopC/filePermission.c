#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

void filePermission(char *path, char *name, char *permissions) {

    char fullPath[1024];
    strcpy(fullPath, path);
    strcat(fullPath, name);
    int fd;

    // Set the desired permissions: read and write for the owner
    mode_t p = (permissions == "RW") ? (S_IRUSR | S_IWUSR) : (permissions == "R") ? S_IRUSR : (permissions == "W") ? S_IWUSR : 0;

    // Create the file with the specified permissions
    fd = open(fullPath, O_CREAT | O_WRONLY, p);
    if (fd == -1) {
        perror("Error creating file");
    }

    // Close the file descriptor
    close(fd);

    printf("File '%s' created with %s for the owner.\n", fullPath, permissions);
}

int main() {
    filePermission("/home/julian-florez/Documentos/ComputerArchitectureAndOperatingSystems/WorkshopC/outFiles/", "example.txt", "RW");
    filePermission("/home/julian-florez/Documentos/ComputerArchitectureAndOperatingSystems/WorkshopC/outFiles/", "example2.txt", "W");
    filePermission("/home/julian-florez/Documentos/ComputerArchitectureAndOperatingSystems/WorkshopC/outFiles/", "example3.txt", "R");
    filePermission("/home/julian-florez/Documentos/ComputerArchitectureAndOperatingSystems/WorkshopC/outFiles/", "example4.txt", "W");
    return 0;
}