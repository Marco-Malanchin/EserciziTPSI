#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>//definiscono la struttura degli indirizzi e funzione del tipo ntohl
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512
#define SERVERPORT 1313

int main(int argc , char** argv){
struct sockdr_in servizio;//Creazione di un elemento di tipo sockaddr
int socketfd; //identificatore della socket
char str1[DIM]; //stringa da mandare al server
char conta; //carattere da contare
int trovato; //volte che e' stato trovato
//Inizializzo l'elemento sockaddr
servizio.sin_family = AF_INET;
servizio.sin_addr.s_addr=htonl(INADDR_ANY);
servizio.sin_port=htons(SERVERPORT);
//Creazione e definizione del Socket
socketfd=socket(AF_INET,SOCK_STREAM,0);
//connessione al server
connect(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));

printf("Inserisci stringa:\n");
scanf("%s", str1);
printf("Inserisci carattere da cercare all'interno della stringa:\n");
scanf("%s", conta);
write(socketfd, str1, sizeof(str1));
write(socketfd, conta, sizeof(conta));
read(socketfd, trovato, sizeof(trovato));
printf("carattere %s , trovato %d volte\n", conta, trovato);
close(socketfd);
return 0;
}