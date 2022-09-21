#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define n 6
int j = 1;
void stampa(int a[]){
    for(int i = 1; i <= n; i++){
        printf("numero %d° dell array: %d\n", i , a[i]);
    }
}
int inverso(int b[]){
    printf("numeri invertiti:\n");
    for(int i = n; i > 0; i--){
        printf("numero %d° dell array: %d\n", j , b[i]);
        j++;
    }
}

int main(int argc, char *argv[]){
    int numeri[n];
    int funzione;
    printf("Generazione dati\n");
    for(int i = 0; i <= n; i++){ 
        numeri[i] = 1 + rand()%100;
    }
    printf("Quale funzione vuoi usare?\n");
    scanf("%d", &funzione);
    switch (funzione){
        case 1:
        printf("Stampo numeri\n");
        stampa(numeri);
        break;
        case 2:
        printf("Inverto numeri\n");
        inverso(numeri);
        break;
        case 3:

        break;
        case 4:

        break;
        case 5:

        break;
        case 6:

        break;
        case 7:

        break;
        case 8:

        break;
        case 9:

        break;
    }
    
    
    return 0;
}