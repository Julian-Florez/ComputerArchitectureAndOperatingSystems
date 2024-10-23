#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


void newFile(char *path, char *name, char *content){
    char fullPath[1024];
    strcpy(fullPath, path);
    strcat(fullPath, name);
    int file = open(fullPath, O_CREAT | O_WRONLY | O_TRUNC, 0644);


    if (file == -1)
    {
        perror("Error");
        return;
    }

    write(file, content, strlen(content));
    close(file);
    printf("File '%s' created.\n", fullPath);
    return;
}

int main(){
    newFile("./outFiles/", "test.txt", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam mollis ex");
    return 0;
}
