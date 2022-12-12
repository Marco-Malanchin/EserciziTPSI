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
    int socketfd;
    char str1[DIM], str2[DIM], newString[DIM];

    servizio.sin_family=AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);

    socketfd = socket(AF_INET, SOCK_STREAM,0);
    
    connect(socketfd,(struct sockaddr*)&servizio, sizeof(servizio));

    printf("inserisci stringa1:...\n");
    scanf("%s", str1);
    write(socketfd, str1, sizeof(str1));

    printf("inserisci stringa2:...\n");
    scanf("%s", str2);
    write(socketfd, str2, sizeof(str2));

    read(socketfd, &newString, sizeof(newString));
    printf("lettere comuni tra le stringhe: %s \n", newString);


    close(socketfd);

    return 0;
}