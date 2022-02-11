#include <stdio.h>
#include <stdlib.h>
// @file Pippo.c
// @author Marco Malanchin
// @date File creato 8/11/2021
/*
* @aggiungiPersona()
* @brief Funzione per aggiungere le persone della struct persona_t all array Persone[]
* @return ritorna la persona con i parametri nome, cognome, ed età
* @confrontoEta(perosne_t persone[])
* @brief Funzione confrontare il parametro eta delle persone dichiarate
* @return ritorna la persona con il perametro eta maggiore
*/
typedef struct //creo la struct persona_t
{
	char nome[100]; //Dichiaro il char nome appartenente alla struct persona_t
	char cognome[100]; //Dichiaro il char cognome appartenente alla struct persona_t
	int eta; //Dichiaro int eta appartenente alla struct persona_t
}persona_t;

persona_t aggiungiPersona() //dichiaro la funzione della struct persona_t che servirà per dichiarare le persone utili per il confronto successivo
{	
        persona_t persona; //richiamo la struct persona_t assegnadole la variabile persona 
		printf("Inserisci nome della persona:"); //chiedo il nome della variabile persona
		scanf("%s", persona.nome); //assegno alla variabile persona il parametro nome
		printf("Inserisci cognome della persona:"); //chiedo il cognome della variabile persona
		scanf("%s", persona.cognome); //assegno alla variabile persona il parametro cognome
		printf("Inserisci l'eta' della persona:"); //chiedo l'età della variabile persona
		scanf("%d", &persona.eta); //assegno alla variabile persona il parametro eta
        return persona; // faccio ritornare la variabile persona che comprende i parametri nome cognome eta
}
persona_t confrontoEta(persona_t persone[]) //dichiaro la funzione della struct persona_t che servirà per controllare l'eta maggiori tra le persone inizializzate in precedenza
{
	int etaMassima = 0; //Inizializzo la variabile utile per il confronto d'età a 0
	persona_t personaVecchia;// richiamo la strcut persona_t assegnandoli la variabile PersonaVecchia
	for(int i = 0; i < 4; i++)// creo il ciclo for che andrà a confrontare l'età delle persone per scoprire la più vecchia
	{
		if(persone[i].eta > etaMassima ) // se il parametro età della persona confrontata sarà maggiore della in etaMassima attuale allora ->
		{
			etaMassima = persone[i].eta; //-> l'int etaMassima assumera il valore dell'eta della persona confrontata 
			personaVecchia = persone[i];// la variabile persona vecchia sarà uguale alla persona con l'int eta maggiore
		}
	}
    return personaVecchia;// faccio ritornare la variabile personaVecchia con i parametri nome cognome e eta
}

int main(int argc, char *argv[]) 
{   
    persona_t Persone[4];//richiamo la struct persona_t con variabile Persone[4] le quali saranno le persone che inizializzerò
    for (int i = 0; i < 4; i++) //Con il ciclo for richiamo la variabile aggiungiPersona inizializzando alla variabile Persone[] nome cognome eta 
    {
        Persone[i] = aggiungiPersona();
    }
    persona_t Vecchio; //dichiaro la variabile Vecchio
	Vecchio = confrontoEta(Persone);// alla variabile Vecchio richiamo la funzione confrontoEta per assegnare alla variabile Vecchio l'età della persona più vecchia
	printf("la persona più vecchia e' %s", Vecchio.nome);//stampo a schermo il nome della persona più vecchia
    return 0;
}