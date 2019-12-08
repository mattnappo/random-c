#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_CLIENTS 5

int main()
{
    int port = 9090;
    
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = INADDR_ANY;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(
      server_socket,
      (struct sockaddr *) &server_address,
      sizeof(server_address)
    );

    int client_count = 0;

    printf("awaiting connections\n");
    listen(server_socket, MAX_CLIENTS);

    return 0;
}