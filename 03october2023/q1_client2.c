/* WAP to connect two clients and server and perform the following.
1. Client 1 will send a no, client 2 will send a no, server will calculate the product and display on client 1.
2. Chat between both the clients through servers.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

void error(const char *message) {
    perror(message);
    exit(1);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

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

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    int num2, product;
    char message[256];

    // Input number
    printf("Enter a number: ");
    scanf("%d", &num2);

    // Send the number to the server
    send(sockfd, &num2, sizeof(num2), 0);

    // Receive and print the product from the server
    recv(sockfd, &product, sizeof(product), 0);
    printf("Product received from server: %d\n", product);

    // Chat functionality
    while (1) {
        printf("You (Client 2): ");
        fgets(message, sizeof(message), stdin);
        send(sockfd, message, sizeof(message), 0);

        memset(message, 0, sizeof(message));

        recv(sockfd, message, sizeof(message), 0);
        printf("Client 1: %s", message);
    }

    // Close the socket
    close(sockfd);

    return 0;
}
