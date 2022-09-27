#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define n 6
void inserisci(int z[]){
    for(int i = 0; i < n; i++){// inserisco 6 numeri dentro all'array
        printf("inserisci numeri:\n");
        scanf("%d", &z[i]);
    }
}
void stampa(int a[]){
    for(int i = 0; i < n ; i++){//ogni elemento dell array lo stampo a schermo
        printf("numero %d° dell array: %d\n", i + 1 , a[i]);
    }
}
void inverso(int b[]){
    printf("numeri invertiti:\n");
    int j = 0;
    for(int i = n- 1; i >= 0; i--){//parto dall ultimo numero dell array - 1 e lo comincio a stampare finche non raggiunge il numero in posizione 0
        printf("numero %d° dell array: %d\n", j + 1 , b[i]);
        j++;
    }
}
void sommaMedia(int c[]){ //sommo tutti i numeri dell array in una int e poi li divido per il numero dei numeri
    int totale = 0;
    float media = 0;
    for(int i = 0; i < n; i++){
        totale += c[i];
    }
    media = totale/n;
    printf("totale %d\n", totale);
    printf("media: %f\n", media);
}
void pari(int d[]){ // stampo solo i numeri che diviso 2 mi daranno un risulatato 0, ovvero i pari
    for(int i = 0; i < n; i++){
        if (d[i]%2==0){
        printf("numeri pari:%d\n" , d[i]); 
        }

    }
}
void dispari(int e[]){// stampo i numeri che non mi daranno risultato 0
    for(int i = 0; i < n; i++){
        if (e[i]%2!=0){
        printf("numeri dispari:%d\n" , e[i]); 
        }
    }
}
void cerca(int f[]){
    int contatore;
    int ricerca;// prendo un numero da cercare e controllo ogni elemento dell array se corrisponde a quel numero, se corrispinde aumneto una variabile contatore e dico all'utente quante volte ho trovato il numero
    printf("Inserisci numero da cercare:\n");
    scanf("%d", &ricerca);
    for(int i = 0; i < n; i++){
        if(ricerca == f[i]){
            contatore++;
        }
    }
    printf("Numero %d trovato %d volte", ricerca, contatore);
}
void elimina(int g[])
{
    int eliminare = 0;//inserisco il numero da eliminare e controllo per ogni posizione dell array, se trovo il numero lo sostituisco con il numero successivo
    printf("Inserisci un numero da eliminare\n");
    scanf("%d", &eliminare);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (g[i] != eliminare)
        {
            g[j++] = g[i];
        }
    }
    for (int i = 0; i < j; i++)//stampo di nuovo i numeri
    {
        printf("%d ", g[i]);
    }
    
}
void scambia(int h[])
{
    int tmp = 0, i = 1; // assegno ad una variabile temporanea il secondo numero delle coppie
    while (i < n)
    {
        tmp = h[i];
        h[i] = h[i - 1]; //assegno il primo numero della coppia alla posizione due
        h[i - 1] = tmp; // e alla posizione uno assegno il primo valore della coppia
        i += 2;
    }
    for(int i = 1; i <= n ; i++){
        printf("numero %d° dell array: %d\n", i, h[i-1]);
    }
}
void riordina(int k[])
{
    for (int i = 0; i < n; i++) // per ogni elemento dell'array confronto se il numero successivo è più grande ed in caso con una variabile temporanea lo riordino
    {
        for (int j = 0; j < n; j++)
        {
            if (k[j] > k[j + 1])
            {
                int tmp = k[j];
                k[j] = k[j + 1];
                k[j + 1] = tmp;
            }
        }
    }
    for(int i = 1; i <= n ; i++){
        printf("numero %d° dell array: %d\n", i, k[i-1]);
    }
}


int main(int argc, char *argv[]){
    int numeri[n];
    int funzione;
    inserisci(numeri);
    do{
        printf("Quale funzione vuoi usare?\n");
        printf("1 stampa i numeri dell'array\n");
        printf("2 stampa i numeri dell'array al contrario\n");
        printf("3 somma e media dei numeri degli array\n");
        printf("4 stmapa i numeri pari\n");
        printf("5 stampa i numeri dispari\n");
        printf("6 ricerca un numero nell'array\n");
        printf("7 elimina un numero dell'array\n");
        printf("8 Alterna a due a due le posizioni dell'array\n");
        printf("9 ordina l'array\n");
        scanf("%d", &funzione);
    }
    while (funzione < 1 || funzione > 9);//chiedo quale funzione vuole usare finchè non inserisce un numero valido
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
        elimina(numeri);
        break;
        case 8:
        scambia(numeri);
        break;
        case 9:
        riordina(numeri);
        break;
    }
    
    
    return 0;
}