#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define n 1000000 //Definisco la dimensione del mio array e i numeri che devo generare

int main(){
    FILE *fp; //creo il puntatore file
    int numeri[n]; //creo l'array dove stanzierò i numeri generati
    int i, j;
    srand(time(0)); // metto come seed del random il tempo corrente
    if ((fp = fopen("dati.txt", "w+"))== NULL){ // se il file non si apre avverto dell'errore ed esco dalla compilazione
        printf("Errore generazione file\n");
        return -1;
    }
    printf("Generazione dati\n");
    for(int i = 0; i <= n; i++){ 
        numeri[i] = 1 + rand()%1500000;//Genero i dati e li inserisco dentro all array
        for(int j = 0; j < i; j++){
            if(numeri[i] == numeri[j]){ //controllo che un dato non sia già stato scritto
                i--;//se è stato scritto tolgo un valore dal for per generare un altro dato
                break;
            }
            else if(j == i - 1){ //se invece sono arrivato a controllare tutti i numeri stampo sul foglio il numero generato
                fprintf(fp,"%d\n",numeri[i]);
            }
       }    
    }
    fclose(fp);//chiudo il file alla fine della generazione dei numeri
    printf("Generazione completata");
    return 0;
}