#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512 //dimensione della stringa
#define SERVERPORT 1313 // indichiamo la porta logica

int main(int argc,char** argv)
{   
    struct sockaddr_in servizio;
    int socketfd;
    char str1[DIM]; // stringa che mando al server

    servizio.sin_family=AF_INET; //tipo di famiglia socket
    servizio.sin_addr.s_addr=htonl(INADDR_ANY); //indirizzo ip localhost
    servizio.sin_port=htons(SERVERPORT); //numero di porta

    socketfd=socket(AF_INET,SOCK_STREAM,0); //creo la socket 

    connect(socketfd,(struct sockaddr*)&servizio,sizeof(servizio)); //conneto la socket
    
    printf("Inserisci la stringa\n"); // chiedo la stringa all'utente
    scanf("%s",str1);// leggo la stringa
    write(socketfd,str1,sizeof(str1));// la mando al server
    
    close(socketfd);// chiudo la socket

    return 0;
}
