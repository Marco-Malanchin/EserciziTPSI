#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <strings.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Compilazione programma errata\n");
        exit(0);
    }
    int pid1, pid2, totale = 0;
    char codice[10], risultato[50], ris2[50];
    int canale1[2], canale2[2];
    pipe(canale1);
    pipe(canale2);
    do
    {
        printf("Inserisci codice cliente\n");
        scanf("%s", codice);
        pid1 = fork();
        if(pid1 == 0)
        {
            close(1);
            dup(canale1[1]);
            close(canale1[1]);
            execlp("/bin/grep", "grep", "-c", codice, argv[1], NULL);
        }
        else
        {
            read(canale1[0], risultato, sizeof(risultato));
            if(atoi(risultato) > 0)
            {
                pid2 = fork();
                if(pid2 == 0)
                {
                    close(1);
                    dup(canale2[1]);
                    close(canale2[1]);
                    strcat(codice, " insoluto");
                    execlp("/bin/grep", "grep", "-c", codice, argv[1], NULL);
                }
                read(canale2[0], ris2, sizeof(ris2));
                printf("Sono stati trovati %i insoluti\n", atoi(ris2));
                totale = totale + atoi(ris2);
            }
            else
            {
                printf("Codice cliente inesistente\n");
                
            }
        }
    }while(strcmp(codice, "Fine") != 0);
    printf("Sono stati trovati %i insoluti\n", totale);

    return 0;
}