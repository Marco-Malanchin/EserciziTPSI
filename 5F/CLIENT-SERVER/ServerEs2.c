#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>


#define DIM 512
#define SERVERPORT 62400

void clearBuffer(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = 0;
    }
    
}

int ricercaCarattere(char str1[], char carattere[])
{
    int contatore = 0;
    for(int i = 0; i < strlen(str1); i++){
        if(str1[i] == carattere[0]){
            contatore++;
        }   
    }   
    return contatore;
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio), result;
    char str[DIM], carattere[1];
    //definizione dati socket

    servizio.sin_family = AF_INET;
    servizio.sin_port = htons(SERVERPORT);
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    

     // impostazione del transport endpoint del server
    socketfd=socket(AF_INET,SOCK_STREAM,0); //creo la socket
    // leghiamo l'indirizzo al transport endpoint
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));

     //mettiamo il server in ascolto
    listen(socketfd,10);

    //ciclo infinito
     while(1)
     {

        printf("\n in ascolto....\n");

        soa = accept(socketfd, (struct sockaddr*)&addr_remoto, &fromlen);

        read(soa, str, DIM);
        printf("stringa ricevuta: %s\n", str);
        read(soa, carattere, 1);
        printf("carattere ricevuto: %c\n", carattere[0]);
        printf("stringa e carattere confrontato\n");
        result = ricercaCarattere(str, carattere);
        write(soa, &result, sizeof(int));
        clearBuffer(str);
        close(soa);
     
     }
    
    return 0;

}