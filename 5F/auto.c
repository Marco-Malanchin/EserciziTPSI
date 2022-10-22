#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 10

void frequenza(int numeri[], int dim){
    int contatore = 0;
    int frequenza = 0;
    int frequente;
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < i; j++){
            if(numeri[j] == numeri[i]){
                contatore++;
            }
        }
        if(contatore > frequenza){
                frequenza = contatore;
                frequente = numeri[i];
        }
        contatore = 0;
    }
    printf("numero che si ripete più volte: %d, si ripete %d volte\n", frequente, frequenza + 1);
}
void sposta(int numeri[], int dim){
    int temp;
    int ripeti;
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(numeri[i] == numeri[j]){
                ripeti++;
            }
        }
    }
    for(int i = 0; i < DIM; i++){
        printf("%d° numero: %d", i+1, numeri[i]);
    }
}
void riordina(int numeri[], int dim){
    int cntPari = 0;
    int cntDispari = 0;
    int temp;
    int numeriPari[DIM];
    int numeriDispari[DIM];
    for(int i = 0; i < dim-1; i++){
        for(int j = 0; j < dim-1; j++) {
            if(numeri[j] > numeri[j + 1]){
                temp = numeri[j];
                numeri[j] = numeri[j + 1];
                numeri[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < dim; i++){  
        if((numeri[i] % 2) == 0){
            numeriPari[cntPari] = numeri[i];
            cntPari++;
        }
        else if((numeri[i] % 2) != 0){
            numeriDispari[cntDispari] = numeri[i];
            cntDispari++;
        }
    }
    for(int i = 0; i < cntDispari - 1; i++){
        for(int j = 0; j < cntDispari - 1; j++) {
            if(numeriDispari[j] < numeriDispari[j + 1]){
                temp = numeriDispari[j];
                numeriDispari[j] = numeriDispari[j + 1];
                numeriDispari[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < cntPari; i++){
        numeri[i] = numeriPari[i];
    }
    for(int i = 0; i < cntDispari; i++){
        numeri[i + cntPari] = numeriDispari[i];
    }
    for(int i = 0; i < dim; i++){
        printf("%d° numero: %d\n", i+1, numeri[i]);
    }
}

int main(){
    int numeri[DIM];
    for(int i = 0; i < DIM; i++){
        printf("Inserisci numero\n");
        scanf("%d", &numeri[i]);
    }
    frequenza(numeri, DIM);
    
    riordina(numeri, DIM);

    return 0;
}