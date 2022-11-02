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

#define DIM 512
#define SERVERPORT 1313

int contaCarattere(char str[], char conta[], int dim){
    int trovato = 0;
    for(int i = 0; i < dim; i++){
        if(conta[0] = str[i]){
            trovato++;
        }
    }
    return trovato;
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;// record con i dati del server e del client
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM], conta[1];
    int trovato;
    //definisco i dati della socket
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr= htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVERPORT);
    //imposto il transport endpoint del server
    socketfd=socket(AF_INET,SOCK_STREAM,0);
    //leghiamo l'indirizzo al transport endpoint
    bind(socketfd, (struct sockaddr*)&servizio, sizeof(servizio));
    //poniamo il server in ascolto 5 client
    listen(socketfd,5); //attende fino a 5 client
    //ciclo infinito
    while(1){
        printf("server in ascolto... \n");
        fflush(stdout);
        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        //leggo dal client
        read(soa,str,sizeof(str));
        read(soa,conta,sizeof(conta));
        printf("stringa e carattere ricevuti\n");
        printf("carattere %s trovato %d volte" , conta, contaCarattere(str,conta,sizeof(str)));
        write(soa,contaCarattere(str,conta,sizeof(str)), sizeof(contaCarattere));
        close(soa);
    }
    return 0;
}
