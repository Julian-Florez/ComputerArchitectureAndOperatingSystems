#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void listFilesRecursively(char *basePath);

int main() {
    char path[1000];

    // Specify the directory path here
    strcpy(path, "/");

    listFilesRecursively(path);

    return 0;
}

void listFilesRecursively(char *basePath) {
    char path[1000];
    struct dirent *dp;
    struct stat fileStat;
    DIR *dir = opendir(basePath);

    // Unable to open directory stream
    if (!dir) {
        return;
    }

    while ((dp = readdir(dir)) != NULL) {
        // Construct new path from our base path
        strcpy(path, basePath);
        strcat(path, "/");
        strcat(path, dp->d_name);

        // Skip the "." and ".." entries
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            if (stat(path, &fileStat) == 0) {
                FILE *file = fopen("/home/julian-florez/Documentos/ComputerArchitectureAndOperatingSystems/FilesInDisk/sizes.txt", "a");
                if (file == NULL) {
                    perror("Unable to open file");
                    exit(EXIT_FAILURE);
                }
                if (fileStat.st_size >0 && fileStat.st_size < 1000000) {
                    fprintf(file, "%ld\n",fileStat.st_size);
                }
                fclose(file);
            }

            // Recursively call with the new path
            listFilesRecursively(path);
        }
    }

    closedir(dir);
}