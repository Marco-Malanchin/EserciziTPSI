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
int sommaMedia(int c[]){
    double totale;
    double media;
    for(int j = 1; j <= n; j++){
        printf("numero %d° dell array: %d\n", j , c[j]);
    }
    for(int i = 0; i < n; i++){
        totale += c[i];
    }
    media = totale/n;
    printf("totale %lf\n", totale);
    printf("media: %lf\n", media);
}
int pari(int d[]){
    for(int i = 0; i < n; i++){
        if (d[i]%2==0){
        printf("numeri pari:%d\n" , d[i]); 
        }

    }
}
int dispari(int e[]){
    for(int i = 0; i < n; i++){
        if (e[i]%2!=0){
        printf("numeri dispari:%d\n" , e[i]); 
        }
    }
}
int cerca(int f[]){
    int contatore;
    int ricerca;
    for(int i = 1; i <= n; i++){
        printf("numero %d° dell array: %d\n", i , f[i]);
    }
    printf("Inserisci numero da cercare:\n");
    scanf("%d", &ricerca);
    for(int i = 0; i < n; i++){
        if(ricerca == f[i]){
            contatore++;
        }
    }
    printf("Numero %d trovato %d volte", ricerca, contatore);
}
int main(int argc, char *argv[]){
    int numeri[n];
    int funzione;
    srand(time(NULL));
    printf("Generazione dati\n");
    for(int i = 0; i <= n; i++){ 
        numeri[i] = rand()%100;
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
        sommaMedia(numeri);
        break;
        case 4:
        pari(numeri);
        break;
        case 5:
        dispari(numeri);
        break;
        case 6:
        cerca(numeri);
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