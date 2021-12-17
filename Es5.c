#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>

int main()
{
    int pid;
    int canale1[2]; //creo due canali uno per la scrittura e uno per la lettura
    int canale2[2];
    pipe (canale1);
    pipe (canale2);
    int numeri[10]; //creo l'array dove andrò a collocare i numeri generati
    int somma = 0;
    pid = fork(); //faccio la fork
    if (pid > 0){ //parto dal padre
        close(canale1[0]); //chiudo i canali che non mi servono
        close(canale2[1]);
        srand(time(0)); //uso la funzione srand che si basa sul orario di esecuzione del programma, ogni volta i numeri generati sono diversi
        printf("numeri generati: \n");
        for(int i = 0; i < 10; i++){
            numeri[i]= rand() % 100 + 1; // genero i miei 10 numeri randomici tra 1 e 100
            printf("%i\n", numeri[i]);
            write(canale1[1], &numeri[i], 10); //ogni volta che genero un numero lo scrivo nella pipe.
        }
        close(canale1[1]); //alla fine del processo chiudo i canali utilizzati
        read(canale2[0], &somma, sizeof(int)); //legge dal figlio la somma dei 10 numeri
        printf("\nLa somma dei numeri generati randomicamente e': %i\n", somma);
        close(canale2[0]); //alla fine del processo chiudo i canali utilizzati
    }
    else if (pid == 0){
        close(canale1[1]);
        close(canale2[0]);
        for (int i = 0; i < 10; i++){
            read(canale1[0], &numeri[i], 10); //legge i 10 numeri generati random e li somma
            somma = somma + numeri[i];
        }
        write(canale2[1], &somma, sizeof(int)); //scrive la somma al padre
        close(canale1[0]); //alla fine del processo chiudo i canali utilizzati
        close(canale2[1]);
    }
    return 0;    
}
