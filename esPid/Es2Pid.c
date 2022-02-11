#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
    int pid, pid1, pid2, pid3, status;
    FILE * file=fopen("pipppo.txt", "w+");
    if(file==NULL)
    {
        printf("Errore!!!!!!!!!!!!!!!!!!!!!");
        exit(0);
    }
    pid1=fork();
    if(pid1==0)
    {
       fprintf(file, "Canarino") ;
       sleep(1);
       exit(1);
    }else
    {
        pid2=fork();
        if(pid2==0)
        {
            fprintf(file, " rosso ");
            sleep(2);
            exit(2);
        }else
        {
            pid3=fork();
            if(pid3==0)
            {
                fprintf(file, "blu");
                sleep(3);
                exit(3);
            }else
            {
                fclose(file);
                waitpid(pid3,& status,0);
                return 0;
            }
        }
   
    }
   