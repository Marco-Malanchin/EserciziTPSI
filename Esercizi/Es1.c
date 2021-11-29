#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char *argv)
{
    int pid;
    if (pid == 0)
    {
        printf("ao sono il processo figlio");
        exit(1);
    }
    else
    {
         printf("ao il pid del processo e':%d", getpid());
         printf("ao sono il padre");
         wait(&pid);
         exit(0);
    }
    return 0;
}