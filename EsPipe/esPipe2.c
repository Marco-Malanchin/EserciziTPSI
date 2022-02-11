#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    int status;
    int canale[2]; //creo la mia pipe
    int pid1, pid2; //creo 2 processi 1 per la lettura del file e l'altro per contare le parole
    pipe(canale);
    pid1 = fork();
    if(pid1 == 0) //creo il processo per la lettura
    {
        close(1); //chiudo il canale 1
        dup(canale[1]);//duplico il canale 1
        close(canale[1]);//chiudo l'originale
        close(canale[0]);
        execlp("/bin/cat", "cat", "File.txt", NULL);//eseguo la lettura del mio file
        printf("Errore comando cat");
        exit(0);
    }
    else
    {
        pid2 = fork();//creo il processo per contare le parole
        if(pid2 == 0)
        {
            close(0);//chiudo canale 0
            dup(canale[0]);//duplico canale 0
            close(canale[0]);//chiudo l'originale
            close(canale[1]);
            execlp("/bin/wc", "wc", NULL); //eseguo la conta delle parole, frasi, lettere
            printf("Errore comando wc");
            exit(1);
        }
        else
        {
            wait(&status);
            close(canale[0]);
            close(canale[1]);
            return 0;
        }
    }
}