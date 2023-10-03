/* WAP to connect two clients and server and perform the following.
1. Client 1 will send a no, client 2 will send a no, server will calculate the product and display on client 1.
2. Chat between both the clients through servers.*/
// Server.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

void error(const char *message) {
    perror(message);
    exit(1);
}

int main() {
    int sockfd, client1_sock, client2_sock;
    struct sockaddr_in server_addr, client1_addr, client2_addr;
    socklen_t client1_len, client2_len;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Initialize server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error on binding");
    }

    // Listen for incoming connections
    listen(sockfd, 2);

    // Accept client 1
    client1_len = sizeof(client1_addr);
    client1_sock = accept(sockfd, (struct sockaddr *)&client1_addr, &client1_len);
    if (client1_sock < 0) {
        error("Error accepting client 1");
    }

    // Accept client 2
    client2_len = sizeof(client2_addr);
    client2_sock = accept(sockfd, (struct sockaddr *)&client2_addr, &client2_len);
    if (client2_sock < 0) {
        error("Error accepting client 2");
    }

    // Communication loop
    while (1) {
    int num1, num2, product;
    char message[256];

    // Receive numbers from client 1
    recv(client1_sock, &num1, sizeof(num1), 0);

    // Receive numbers from client 2
    recv(client2_sock, &num2, sizeof(num2), 0);

    // Calculate the product
    product = num1 * num2;

    // Send the product to client 1
    send(client1_sock, &product, sizeof(product), 0);

    // Receive and forward messages between clients
    memset(message, 0, sizeof(message));

    // Receive message from client 1
    recv(client1_sock, message, sizeof(message), 0);

    // Send the message to client 2
    send(client2_sock, message, sizeof(message), 0);

    // Receive message from client 2
    recv(client2_sock, message, sizeof(message), 0);

    // Send the message to client 1
    send(client1_sock, message, sizeof(message), 0);
    }
    // Close sockets
    close(client1_sock);
    close(client2_sock);
    close(sockfd);

    return 0;
}
