#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void process_directory(const char *dir_path, long *total_size, long *file_count) {
    struct dirent *entry;
    struct stat file_stat;
    char full_path[1024];

    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
        if (stat(full_path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            process_directory(full_path, total_size, file_count);
        } else if (S_ISREG(file_stat.st_mode)) {
            *total_size += file_stat.st_size;
            (*file_count)++;
        }
    }

    closedir(dir);
}

int main() {
    const char *root_path = "/";
    long total_size = 0;
    long file_count = 0;

    process_directory(root_path, &total_size, &file_count);

    if (file_count > 0) {
        printf("Total size of files: %ld bytes\n", total_size);
        printf("Total number of files: %ld\n", file_count);
        printf("Average file size: %ld bytes\n", total_size / file_count);
    } else {
        printf("No files found.\n");
    }

    return 0;
}