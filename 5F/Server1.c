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


int main()
{
    struct sockaddr_in servizio, addr_remoto;// record con i dati del server e del client, pag 161
    int socketfd, soa, fromlen=sizeof(servizio);
    char str[DIM]; // stringa che memorizzo
    // definizione dei dati del socket , pag 114
    servizio.sin_family=AF_INET; //tipo di famiglia socket
    servizio.sin_addr.s_addr=htonl(INADDR_ANY); // indirizzo ip
    servizio.sin_port=htons(SERVERPORT); // numero di porta
    // impostazione del transport endpoint del server
    socketfd=socket(AF_INET,SOCK_STREAM,0); //creo la socket
    // leghiamo l'indirizzo al transport endpoint
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    // poniamo il server in ascolto delle richieste dei client 
    listen(socketfd,10);// può attendere fino a 10 client
    // ciclo infinito
    while (true) // si puo anche fare con for (; ;) 
    {
        printf("\n\nServer in ascolto...");

        fflush(stdout); // pulisce il canale di comunicazione

        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        //legge dal client
        read(soa,str,sizeof(str));
        
        printf("Stringa ricevuta: %s\n",str); // scrive
        
        close(soa);

     }
      
   return 0;
    
}
