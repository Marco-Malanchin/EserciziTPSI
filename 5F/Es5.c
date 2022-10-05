#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>


void inserisci(int a[], int dim){
    int numero;
    printf("Digita numero da inserire\n");
    scanf("%d", &numero);
    a[dim++] = numero;
    printf("stampo numeri\n");
    for(int i = 0; i < dim; i++){
        printf("%d° numero: %d\n" , i+ 1, a[i]);
    }
}

int main(){
    int numero[5];
    size_t lunghezza = sizeof(numero)/sizeof(numero[0]);
    for(int i = 0;i < lunghezza;i++){
        printf("inserisci %d° numero\n" , i+1);
        scanf("%d", &numero[i]);
    }
    inserisci(numero, lunghezza);
    return 0;
}