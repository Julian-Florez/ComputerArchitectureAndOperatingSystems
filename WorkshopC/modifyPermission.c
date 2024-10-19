#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

void modifyPermission(char *file, char *permissions){

    mode_t p = (permissions == "RW") ? (S_IRUSR | S_IWUSR) : (permissions == "R") ? S_IRUSR : (permissions == "W") ? S_IWUSR : 0;

    chmod(file, p);
}


int main(){
    modifyPermission("/home/julian-florez/Documentos/ComputerArchitectureAndOperatingSystems/WorkshopC/outFiles/example4.txt", "RW");
    return 0;
}