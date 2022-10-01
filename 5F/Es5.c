#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void controlloNumeri(char a[], int dim){
    for(int i = 0; i < dim; i++){
        if((a[i] >= 48) && (a[i] <= 57)){
        printf("Numero trovato in posizione %d\n", i + 1);
        }
    }
}
void controlloVocaliConsonanti(char a[], int dim){
    int cntVocali = 0;
    int cntConsonanti = 0;
    int cntNumeri = 0;
    for(int i = 0; i < dim; i++){
        if((a[i] >= 48) && (a[i] <= 57)){
            cntNumeri++;
        }
        else if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
            cntVocali++;
        }
        else{
            cntConsonanti++;
        }
    }
    printf("Numero vocali : %d\n", cntVocali);
    printf("Numero consonanti : %d\n", cntConsonanti);
}
void ricercaParola(char a[], int dim){
    int cntLettera = 0;
    char ricerca;
    printf("inserisci lettera da ricercare\n");
    scanf("%s", &ricerca);
    for(int i = 0; i < dim; i++){
        if(ricerca == a[i]){
            cntLettera++;
        }
    }
    printf("Lettera trovata : %d volte\n", cntLettera);
}
void generaStringhe(char a[], int dim, char pari[], char dispari[]){
int cntNumeri = 0;
    for(int i = 0; i < dim; i++){
        if((a[i] >= 48) && (a[i] <= 57)){
            cntNumeri++;
        }
        else if((i%2) == 0){
        strncat(pari, &a[i], 1);
        }
        else{
        strncat(dispari, &a[i], 1);
        }
    }
}
int main(){
    char parola[100];
    char pari[100];
    char dispari[100];
    printf("inserisci stringa\n");
    scanf("%s", parola);
    controlloNumeri(parola, strlen(parola));
    controlloVocaliConsonanti(parola, strlen(parola));
    ricercaParola(parola,strlen(parola));
    generaStringhe(parola,strlen(parola), pari, dispari);
    printf("Stringa che contengono le lettere in posizione pari: %s\n", pari);
    printf("Stringa che contengono le lettere in posizione dispari: %s\n", dispari);
    return 0;
}