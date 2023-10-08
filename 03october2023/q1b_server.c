/* WAP to connect two clients and server and perform the following.
a. Client 1 will send a no, client 2 will send a no, server will calculate the product and display on client 1.
b. Chat between both the clients through servers.*/
// Server.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int server_socket, client_socket1, client_socket2;
    struct sockaddr_in server_addr, client_addr1, client_addr2;
    socklen_t addr_size = sizeof(struct sockaddr_in);
    char buffer[1024];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 2) == 0) {
        printf("Listening...\n");
    } else {
        perror("Listening failed");
        exit(1);
    }

    // Accept two client connections
    client_socket1 = accept(server_socket, (struct sockaddr *)&client_addr1, &addr_size);
    printf("Client 1 connected\n");
    client_socket2 = accept(server_socket, (struct sockaddr *)&client_addr2, &addr_size);
    printf("Client 2 connected\n");

    while (1) {
        // Receive a message from client 1 and send it to client 2
        memset(buffer, 0, sizeof(buffer));
        recv(client_socket1, buffer, sizeof(buffer), 0);
        printf("Client 1: %s\n", buffer);
        send(client_socket2, buffer, strlen(buffer), 0);

        // Receive a message from client 2 and send it to client 1
        memset(buffer, 0, sizeof(buffer));
        recv(client_socket2, buffer, sizeof(buffer), 0);
        printf("Client 2: %s\n", buffer);
        send(client_socket1, buffer, strlen(buffer), 0);
    }

    // Close the sockets
    close(server_socket);
    close(client_socket1);
    close(client_socket2);

    return 0;
}
