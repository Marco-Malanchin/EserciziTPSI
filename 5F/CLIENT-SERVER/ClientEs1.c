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
#include <arpa/inet.h>

#define DIM 512
#define SERVERPORT 63400
int main(int argc, char** argv)
{
    struct sockaddr_in servizio;
    int socketfd;
    char str1[DIM], str2[DIM]; //stringa che mando al server
    
    servizio.sin_family=AF_INET; //famiglia della socket
    servizio.sin_addr.s_addr=htonl(INADDR_ANY); //indirizzo ip locale
    servizio.sin_port=htons(SERVERPORT); //numero di porta

    socketfd=socket(AF_INET, SOCK_STREAM, 0); //creo socket

    connect(socketfd,(struct sockaddr*)&servizio, sizeof(servizio)); //connetto la socket

    printf("inserisci stringa da verificare se palindroma\n");
    scanf("%s", str1);
    write(socketfd, str1, sizeof(str1));
    read(socketfd, str2, sizeof(str2));
    printf("la stringa inserita e' %s\n", str2);

    close(socketfd);// chiudo la socket

    return 0;

}