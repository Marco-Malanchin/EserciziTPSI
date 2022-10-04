#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
void controlloNumeri(char a[], int dim){
    bool controllo = false;
    for(int i = 0; i < dim; i++){
        if((a[i] >= 48) && (a[i] <= 57)){
        printf("Numero trovato in posizione %d\n", i + 1);
        controllo = true;
        }
    }
    if(controllo == false){
        printf("Numeri non trovati\n");
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
void doppie(char a[], int dim){
    for(int i = 0; i < dim; i++){
        if(a[i]==a[i+1]){
            printf("doppie trovate in posizione %d, %d\n", i+1, i+2);
        }   
    }
}
void lunghezza(int dim1, int dim2){
    if(dim1 > dim2){
        printf("Stringa 1 piu' lunga\n");
    }
    else if(dim1 < dim2){
        printf("Stringa 2 piu' lunga\n");
    }
    else if(dim1 == dim2){
        printf("Stringhe lunghe uguali\n");
    }
}
void doppioni(char a[], char b[], int dim1, int dim2){
    bool controllo = false;
    for(int i = 0; i< dim1; i++){
        for(int j = 0; j< dim2; j++){
            if(a[i]==b[j]){
                controllo = true;
            }
        }
    }
    if(controllo == false){
        printf("Lettere simili non trovate\n");
    }
    else if(controllo == true){
        printf("Lettere simili trovate nelle stringhe\n");
    }
}
void vocaliMaggiori(char a[], char b[], int dim1, int dim2){
    int cntVocali1 = 0;
    int cntVocali2 = 0;
    for(int i = 0; i < dim1; i++){
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
                cntVocali1++;
        }
    }
    for(int i = 0; i < dim2; i++){
        if(b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u'){
                cntVocali2++;
        }
    }
    if(cntVocali1 > cntVocali2){
        printf("Stringa 1 contiene piu' vocali\n");
    }
    else if(cntVocali1 < cntVocali2){
        printf("Stringa 2 contiene piu' vocali\n");
    }
    else if(cntVocali1 == cntVocali2){
        printf("Stringhe con numero vocali uguali\n");
    }
}
void consonantiMaggiori(char a[], char b[], int dim1, int dim2){
    int cntConsonanti1 = 0;
    int cntConsonanti2 = 0;
    int cntVocali1 = 0;
    int cntVocali2 = 0;
    for(int i = 0; i < dim1; i++){
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
                cntVocali1++;
        }
        else{
            cntConsonanti1++;
        }
    }
    for(int i = 0; i < dim2; i++){
        if(b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u'){
                cntVocali2++;
        }
        else{
            cntConsonanti2++;
        }
    }
    if(cntConsonanti1 > cntConsonanti2){
        printf("Stringa 1 contiene piu' consonanti\n");
    }
    else if(cntConsonanti1 < cntConsonanti2){
        printf("Stringa 2 contiene piu' consonanti\n");
    }
    else if(cntConsonanti1 == cntConsonanti2){
        printf("Stringhe con numero consonanti uguali\n");
    }
}
int main(){
    char parola[100];
    char parola2[100];
    char pari[100];
    char dispari[100];
    int scelta;
    int scelta2;
    printf("inserisci stringa\n");
    scanf("%s", parola);
    do{
        printf("Premi 1 per verificare che la stringa contenga solo lettere\n");
        printf("Premi 2 per contare il numero delle vocali e delle consonanti all'interno della stringa\n");
        printf("Premi 3 per contare una lettera se presente nella parola\n");
        printf("Premi 4 per creare due stringhe una la quale contiene solo le lettere in posizione pari l'altra quelle in posizione dispari\n");
        printf("Premi 5 per cercare le doppie nella parola\n");
        scanf("%d", &scelta);
    } while(scelta < 1 || scelta > 5);
    switch(scelta){
        case 1:
            controlloNumeri(parola, strlen(parola));
        break;
        case 2:
            controlloVocaliConsonanti(parola, strlen(parola));
        break;
        case 3:
            ricercaParola(parola,strlen(parola));
        break;
        case 4:
            generaStringhe(parola,strlen(parola), pari, dispari);
            printf("Stringa che contengono le lettere in posizione pari: %s\n", pari);
            printf("Stringa che contengono le lettere in posizione dispari: %s\n", dispari);
        break;
        case 5:
            doppie(parola,strlen(parola));
        break;
    }
    printf("inserisci seconda stringa\n");
    scanf("%s", parola2);
    do{
        printf("Premi 1 per verificare quale stringa e' piu' lunga\n");
        printf("Premi 2 per verificare quali lettere si presentano in entrambe le stringhe\n");
        printf("Premi 3 per controllare quale stringa contiene piu' vocali\n");
        printf("Premi 4 per verificare quale stringa contiene piu' consonanti\n");
        scanf("%d", &scelta2);
    } while(scelta2 < 1 || scelta2 > 4);
    switch(scelta2){
        case 1:
        lunghezza(strlen(parola), strlen(parola2));
        break;
        case 2:
        doppioni(parola, parola2, strlen(parola), strlen(parola2));
        break;
        case 3:
        vocaliMaggiori(parola, parola2, strlen(parola), strlen(parola2));
        break;
        case 4:
        consonantiMaggiori(parola, parola2, strlen(parola), strlen(parola2));
        break;
    }
    return 0;
}