#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
    int status;
    int canale1[2]; //creo la mia pipe per comunicare tra i due figli
    int canale2[2]; //creo la mia pipe per comunicare tra il figlio e il padre
    int pid1, pid2; //creo 2 processi 1 per la lettura del file e l'altro per contare le parole
    pipe(canale1);
    pipe(canale2);
    pid1 = fork();
    if(pid1 == 0) //creo il processo per la lettura
    {
        close(1); //chiudo il canale 1
        dup(canale1[1]);//duplico il canale 1
        close(canale1[1]);//chiudo l'originale
        close(canale1[0]);
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
            dup(canale1[0]);//duplico canale 0
            close(canale1[0]);//chiudo l'originale
            close(canale1[1]); //Prendo in input il file da leggere
            close(1); //chiudo l'output
            dup(canale2[1]); //duplico il canale output della pipe
            close(canale2[1]); //chiudo gli originali
            close(canale2[0]); //passo in output il risultato di wc
            execlp("/bin/wc", "wc", NULL); //eseguo la conta delle parole, frasi, lettere
            printf("Errore comando wc");
            exit(1);
        }
        else
        {
            wait(&status);
            close(0);//chiudo il canale input
            dup(canale2[0]); // duplico il canale input della seconda pipe
            close(canale2[0]); // chiudo gli originali
            close(canale2[1]); // prendo in input il risultato del figlio
            close(canale1[0]); 
            close(canale1[1]);
            close(1); //chiudo l'output
            int FD = open("Test.txt", O_WRONLY); //Apro il file di testo dove scriverò il risultato
            execlp("/bin/tee", "tee", NULL); // scrivo nel file il risultato con il comando tee
            printf("Errore comando tee");
            return 0;
        }
    }
}