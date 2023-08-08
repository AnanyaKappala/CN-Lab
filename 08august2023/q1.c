/* Create sockets for a client and server separately. Bind the sockets with each Machine’s appropriate port and IP 
address. Assume client and server machines are the same machines. Check whether sockets are created or not, binding 
is done properly or not. Display appropriate message.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;

    char server_ip[16];
    int server_port;

    char client_ip[16];
    int client_port;

    printf("Enter server IP address: ");
    scanf("%s", server_ip);
    printf("Enter server port: ");
    scanf("%d", &client_port);
    server_socket = socket(AF_INET, SOCK_STREAM, 0  );
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding server socket");
        close(server_socket);
        exit(1);
    }

    printf("Server socket bound successfully.\n");

    close(server_socket);

    printf("Enter client IP address: ");
    scanf("%s", client_ip);
    printf("Enter client port: ");
    scanf("%d", &client_port);

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating client socket");
        exit(1);
    }

    client_address.sin_family = AF_INET;
    client_address.sin_addr.s_addr = inet_addr(client_ip);
    client_address.sin_port = htons(client_port);

    if (bind(client_socket, (struct sockaddr*)&client_address, sizeof(client_address)) == -1) {
        perror("Error binding client socket");
        close(client_socket);
        exit(1);
    }

    printf("Client socket bound successfully.\n");

    close(client_socket);

    return 0;
}
