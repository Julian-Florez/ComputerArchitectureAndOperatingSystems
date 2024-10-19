#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define FILE_LEN 2048000

void readFile(char *filepath)
{
    int file = open(filepath, O_RDONLY);

    if (file == -1)
    {
        perror("Error");
        return;
    }

    char buffer[FILE_LEN];
    int readBytes = read(file, buffer, FILE_LEN);
    buffer[readBytes] = '\0';
    printf("%s\n", buffer);
}

int main()
{
    readFile("/home/julian-florez/Documentos/ComputerArchitectureAndOperatingSystems/WorkshopC/outFiles/test.txt");
    return 0;
}