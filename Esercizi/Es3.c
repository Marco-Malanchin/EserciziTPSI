#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int pid1, pid2, pid3, status;
    pid1 = fork();
    if(pid1 == 0)
    {
        printf("Ciao, io sono Qui\n");
        exit(1);
    }
    else
    {
        pid2 = fork();
        if(pid2 == 0)
        {
            sleep(1);
            printf("Ciao, io sono Quo\n");
            exit(2);
        }
        else
        {
            pid3 = fork();
            if(pid3 == 0)
            {
                sleep(3);
                printf("Ciao, io sono Qua\n");
                exit(3);
            }
            else
            {
                pid3 = wait(&status);
                return 0;

            }
        }

    }
}