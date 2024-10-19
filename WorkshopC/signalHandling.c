#include <stdio.h> 
#include <signal.h> 
#include <unistd.h>

void sigintHandler(int sig_num) 
{ 
    printf("\n Cannot be terminated using Ctrl+C \n"); 
    fflush(stdout); 
} 

int main () 
{ 
    signal(SIGINT, sigintHandler); 

    while(1) 
    {	
        sleep(1);
        printf("Program running...\n");	 
    } 
    return 0; 
} 
