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

int contaVocali(char str1[])
{
    int contatoreVocali = 0;
    for(int i = 0; i < strlen(str1); i++){
        if(str1[i] == 97 || str1[i] == 101 || str1[i] == 105 || str1[i] == 111 || str1[i] == 117 ){
            contatoreVocali++;
        }   
    }   
    return contatoreVocali;
}
int contaConsonanti(char str1[]){

    int contatoreConsonanti = 0;
    int contatoreVocali = 0;
    for(int i = 0; i < strlen(str1); i++){
        if(str1[i] == 97 || str1[i] == 101 || str1[i] == 105 || str1[i] == 111 || str1[i] == 117 ){
            contatoreVocali++;
        }
        else{
            contatoreConsonanti++;
        }
    }   
    return contatoreConsonanti;
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio), result1, result2;
    char str[DIM];
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
        printf("stringa analizzata\n");
        result1 = contaVocali(str);
        write(soa, &result1, sizeof(int));
        result2 = contaConsonanti(str);
        write(soa, &result2, sizeof(int));
        clearBuffer(str);
        close(soa);
     
     }
    
    return 0;

}