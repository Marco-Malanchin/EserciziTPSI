#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <strings.h>

int main(int argc, char *argv[])
{
    int canale1[2], canale2[2], canale3[2]; 
    int pid1, pid2, pid3;
    char ricerca[50]; 
    char risultato[10];
    int tot = 0;
    int status;
    pipe(canale1); 
    do 
    {   
        printf("inserisci la string che vuoi cercare \n");
        scanf("%s", ricerca); 
        pid1 = fork();
        if(pid1 == 0) 
        {
            close(1); 
            dup(canale1[1]); 
            close(canale1[1]); 
            close(canale1[0]);
            execlp("/bin/cat", "cat", argv[1], NULL);
        }
        else
        {
            pipe(canale2);
            pid2 = fork();
            if(pid2 == 0)
            {
                close(0);
                dup(canale1[0]);
                close(canale1[0]);
                close(canale1[1]);
                close(1);
                dup(canale2[1]);
                close(canale2[1]);
                close(canale2[0]);
                execlp("/bin/grep", "grep", "-o", ricerca, argv[1], NULL);
            }
            else
            {
                pipe(canale3);
                pid3 = fork();
                if(pid3 == 0)
                {
                    close(0);
                    dup(canale2[0]);
                    close(canale2[0]);
                    close(canale2[1]);
                    close(1);
                    dup(canale3[1]);
                    close(canale3[1]);
                    close(canale3[0]);
                    execlp("/bin/wc", "wc", "-l", NULL);
                }
            }
        }
        wait(&status);
        read(canale3[0], risultato , sizeof(risultato));
        printf("La stringa %s e' comparsa %d volte\n\n", ricerca, atoi(risultato));
        tot += atoi(risultato);
    } while(strcasecmp(ricerca, "fine") != 0); 
    close(canale1[0]);
    close(canale1[1]);
    printf("Sono state trovate %i stringhe\n", tot);
    return 0;
}