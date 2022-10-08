#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#define DIM 100


void stampa(int numeri[])
{
    for (int i = 0; i < DIM; i++)
    {
        printf("%d \n", numeri[i]);
    }
}

void riordina(int a[])
{
    for (int i = 0; i < DIM; i++) // per ogni elemento dell'array confronto se il numero successivo è più grande ed in caso con una variabile temporanea lo riordino
    {
        for (int j = 0; j < DIM; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}
void pariDispari(int a[], int cntPari, int cntDispari){
    for(int i = 0; i < DIM; i++) {
        if(a[i] % 2 == 0){
           cntPari++;
        }
        else{
           cntDispari++;
        }
    }
}

void pari(int a[],int temp, int cntPari){
    int p = 0;
    for(int i = 0; i < DIM; i++) {
        if(a[i] % 2 == 0) {
            if(p < cntPari || p < 20) {
                temp = a[p];
                a[p] = a[i];
                a[i] = temp;
                p++; 
            } 
            else{
                i = DIM;
            }	                  
        }            
    }
}
    
void dispari(int a[],int temp, int cntDispari){
int d = 20;
    for(int i = (DIM -1); i > 19; i--) {
        if(a[i] % 2 != 0) {
            if(d < (cntDispari + 20) || d < 40) {
                temp = a[d];
                a[d] = a[i];
                a[i] = temp;
                d++; 
            } 
            else{
                i = 19;
            }	                  
        }            
    }
}
void riordinaDispari(int a[], int temp){
for(int i = 20; i < 40; i++) {
        for(int j = 20; j < 40; j++) {
       	    if(a[j] < a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
} 
    
void riordinaFine(int a[], int temp){
for(int i = 40; i < DIM; i++) {
        for(int j = 40; j < DIM; j++) {
       	    if(a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
    

int main(){
    int numeri[DIM];
    int cntPari; 
    int cntDispari;
    int temp;
    printf("Genero Numeri\n");
    srand(time(NULL));
    for(int i = 0; i <= DIM; i++){ 
        numeri[i] = 1 + rand()%233;//Genero i dati e li inserisco dentro all array
        for(int j = 0; j < i; j++){
            if(numeri[i] == numeri[j]){ //controllo che un dato non sia già stato scritto
                i--;
            }
        }
    }
    riordina(numeri);
    pariDispari(numeri, cntPari, cntDispari);
    pari(numeri, temp, cntPari);
    dispari(numeri, temp, cntDispari);
    riordinaDispari(numeri, temp);
    riordinaFine(numeri, temp);
    stampa(numeri);
    return 0;
}