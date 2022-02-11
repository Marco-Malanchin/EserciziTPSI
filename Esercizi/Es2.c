#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int pid;
    int numero = atoi(argv[1]);
    pid = fork();
    if(pid == 0)
    {   
        numero = numero + 15;
        printf("\nCiao sono il figlio\n");
        printf("numero: %d", numero);
        exit(1);
    }
    else
    {    
        numero = numero + 10;
        printf("\nCiao sono il padre\n");
        printf("numero: %d", numero);
        exit(0);
    }
    return 0;
}