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

void conta(char str1[], char ordinato[], int len){
    int x = 0;
    for(int i = 0; i < len; i++)
    {
        if(isalpha(str1[i]) > 0){
            ordinato[x++] = str1[i];
        }
    }
}
void ordina(char ordinato[], int len){
    
    char tmp[1];
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - 1; j++){
            if(ordinato[j] > ordinato[j+1]){
                tmp[0] = ordinato[j+1];
                ordinato[j+1] = ordinato[j];
                ordinato[j] = tmp[0];
            }
        }
    }
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio), contatore;
    char str[DIM], newString[DIM];
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
        conta(str, newString, strlen(str));
        ordina(newString, strlen(newString));
        printf("stringa ordinata\n");
        write(soa, newString, sizeof(newString));
        clearBuffer(str);
        close(soa);
     
     }
    
    return 0;

}