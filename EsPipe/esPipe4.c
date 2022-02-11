#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <strings.h>

int main(int argc, char *argv[])
{
    int canale[2]; //creo la mia pipe
    int pid;
    char ricerca[50]; //creo la stringa da ricercare
    pipe(canale);
    int tot = 0; //somma delle volte che le stringhe sono state trovate
    char risultato[10]; //numero delle volte che la stringa e' stata trovata
    do 
    {   
        printf("inserisci la string che vuoi cercare \n");
        scanf("%s", ricerca); //prendo in input la stringa da  cercare
        pid = fork();
        if(pid == 0) //creo il processo figlio
        {
            close(0); //chiudo il canale di input
            dup(canale[0]); //duplico il canale di input della pipe
            close(canale[0]); //chiudo l'originale
            close(1); //chiudo il canale di output
            dup(canale[1]); //duplico il canale di output della pipe
            close(canale[1]); //chiudo l'originale
            execlp("/bin/grep", "grep", "-c", ricerca, argv[1], NULL); //con il comando grep - c cerco la stringa all'interno del file e conto quante volte e' stata ripetuta
        }
        read(canale[0], risultato , sizeof(risultato));//leggo dalla pipe quante volte è stata ripetuta la stringa
        printf("La stringa %s e' comparsa %d volte\n\n", ricerca, atoi(risultato));
        tot += atoi(risultato);//sommo il totale di tutte le volte che ho trovato le stringhe
    } while(strcasecmp(ricerca, "fine") != 0); // il programma termina quando la stringa da cercare è uguale a "fine"
    close(canale[0]);
    close(canale[1]);
    printf("Sono state trovate %i stringhe\n", tot);
    return 0;
}