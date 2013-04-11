#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char const *argv[])
{
	int sock,newsock;
	struct sockaddr_in direccion,peer_addr;
    socklen_t peer_addr_size;//SIZE
	char buffer[1500];
	char ipdest[100];
    int port;
    /*---------------CAPTURA IP y PUERTO-------------*/
    if(argc > 2){
        //PASO POR PARAMETROS
        memcpy(ipdest,argv[1],100);
        printf("IP: %s", ipdest);
        port = atoi(argv[2]);

    }
    else{
        //MEDIANTE PROGRAMA
        printf("DAME UNA IP Y/O URL VALIDA:\n");
        scanf("%s", ipdest);
        printf("DAME UN PUERTO:\n");
        scanf("%d",&port);

    }
	
	if((sock = socket(AF_INET,SOCK_STREAM, 0))==-1){
			printf("ERROR ON SOCKET %d", sock);
			exit(0);
	}
	else
		printf("Socket : %d\n",sock );

	direccion.sin_family=AF_INET;// protocolo af inet, visto antes.
	direccion.sin_addr.s_addr=inet_addr(ipdest);//IP necesaria para asignar  
	direccion.sin_port=htons(port);//Puerto necesario arriba de 1024
