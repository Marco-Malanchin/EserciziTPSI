#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>

#define DIM 512
#define SERVERPORT 62400

int main(){
    struct sockaddr_in servizio;
    int socketfd, risultato;
    char str1[DIM], carattere[1];

    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);

    socketfd = socket(AF_INET, SOCK_STREAM,0);
    
    connect(socketfd,(struct sockaddr*)&servizio, sizeof(servizio));

    printf("inserisci stringa:...\n");
    scanf("%s", str1);
    write(socketfd, str1, sizeof(str1));

    printf("\ninserisci carattere...\n");
    scanf("%s", carattere);
    write(socketfd, carattere, 1);

    read(socketfd, &risultato, sizeof(int));
    printf("carattere trovato %d volte\n", risultato);

    close(socketfd);

    return 0;
}