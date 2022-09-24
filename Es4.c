#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define n 6
int j = 1;
void inserisci(int z[]){
    for(int i = 0; i < n; i++){
        printf("inserisci numeri:\n");
        scanf("%d", &z[i]);
    }
}
void stampa(int a[]){
    for(int i = 0; i < n ; i++){
        printf("numero %d° dell array: %d\n", i + 1 , a[i]);
    }
}
void inverso(int b[]){
    printf("numeri invertiti:\n");
    for(int i = n- 1; i >= 0; i--){
        printf("numero %d° dell array: %d\n", j , b[i]);
        j++;
    }
}
void sommaMedia(int c[]){
    int totale = 0;
    float media = 0;
    for(int i = 0; i < n; i++){
        totale += c[i];
    }
    media = totale/n;
    printf("totale %d\n", totale);
    printf("media: %f\n", media);
}
void pari(int d[]){
    for(int i = 0; i < n; i++){
        if (d[i]%2==0){
        printf("numeri pari:%d\n" , d[i]); 
        }

    }
}
void dispari(int e[]){
    for(int i = 0; i < n; i++){
        if (e[i]%2!=0){
        printf("numeri dispari:%d\n" , e[i]); 
        }
    }
}
void cerca(int f[]){
    int contatore;
    int ricerca;
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
    inserisci(numeri);
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