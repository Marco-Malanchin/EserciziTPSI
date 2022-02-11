#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void maiuscolo(char parola[])
{
    for(int i = 0; i < strlen(parola); i++)
    {
        parola[i] = toupper(parola[i]);
    }
}


int main(int argc, char *argv[])
{
    int pid;
    char parola[strlen(argv[1])];
    pid = fork();
    if(pid == 0)
     {
        strcpy(parola,argv[1]);
        maiuscolo(parola);
        printf("la stringa in maiuscolo è: %s\n\n", parola);
        exit(1);
    }else
    {
        wait(&pid);

    }
    return 0;
}