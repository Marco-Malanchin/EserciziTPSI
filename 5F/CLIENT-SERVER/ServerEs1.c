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

int palindromo(char a[], int dim){
    for(int i = 0; i < (dim/2);  i++){
        if(a[i] != a[dim-1-i]){
            return 1;
            break;
        }
        
    }
    return 0;
}

int main(){
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    char str[DIM], str2[DIM];
    //definizione dati socket

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

     // impostazione del transport endpoint del server
    socketfd=socket(AF_INET,SOCK_STREAM,0); //creo la socket
    // leghiamo l'indirizzo al transport endpoint
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));

     //mettiamo il server in ascolto
     listen(socketfd,10);

    //ciclo infinito
     while(1){

        printf("\n in ascolto....\n");
        fflush(stdout);

        soa = accept(socketfd,(struct sockaddr*)&addr_remoto, &fromlen);

        read(soa, str, sizeof(str));
        printf("stringa ricevuta: %s\n", str);
        if(palindromo(str, strlen(str)) == 1){
            strcpy(str2, "non palindromo");
        }
        else{
            strcpy(str2, "palindromo");
        }
        printf("stringa controllata\n");
        write(soa, str2, sizeof(str2));
        close(soa);
     }

  return 0;
}