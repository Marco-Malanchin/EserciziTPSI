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

void confronta(char str1[], char str2[], int len1, int len2, char comuni[]){
    int k = 0;
    int controllo = 0;
    for(int i = 0; i < len1; i++)
    {
        for(int j = 0; j < len2; j++)
        {
            if(str1[i] == str2[j]){
                for(int z = 0; z < k; z++){
                    if(comuni[z] == str1[i]){
                    controllo = 1;    
                    }
                }
                if(controllo == 0){
                    comuni[k++] = str1[i];
                }
                controllo = 0;
            }
        }
    }
}


int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio), contatore;
    char str1[DIM], str2[DIM], newString[DIM];
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

        read(soa, str1, DIM);
        printf("stringa ricevuta: %s\n", str1);
   
        read(soa, str2, DIM);
        printf("stringa ricevuta: %s\n", str2);
   
        confronta(str1, str2, strlen(str1), strlen(str2), newString);
        printf("stringhe controllate\n");
        write(soa, newString, sizeof(newString));
        clearBuffer(str1);
        clearBuffer(str2);
        close(soa);
     
     }
    
    return 0;

}