#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int directoryHandling(char *path, char *operation) {
    char cwd[1024];
    
    // Get and display the current working directory
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }

    if(operation == "create"){
        // Create a new directory
        if (mkdir(path, 0755) == 0) {
            printf("Directory '%s' created successfully.\n", path);
        } else {
            perror("mkdir() error");
            return 1;
        }
    }else if(operation == "remove"){
        // Remove the created directory
        if (rmdir(path) == 0) {
            printf("Directory '%s' removed successfully.\n", path);
        } else {
            perror("rmdir() error");
            return 1;
        }
    }else{
        printf("Invalid operation\n");
        return 1;
    }
    return 0;
}

int main() {
    directoryHandling("/home/julian-florez/Documentos/ComputerArchitectureAndOperatingSystems/WorkshopC/outFiles/testDir", "create");
    directoryHandling("/home/julian-florez/Documentos/ComputerArchitectureAndOperatingSystems/WorkshopC/outFiles/testDir2", "create");
    directoryHandling("/home/julian-florez/Documentos/ComputerArchitectureAndOperatingSystems/WorkshopC/outFiles/testDir2", "remove");
    return 0;
}