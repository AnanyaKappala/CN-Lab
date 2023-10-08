/* WAP to connect two clients and server and perform the following.
1. Client 1 will send a no, client 2 will send a no, server will calculate the product and display on client 1.
2. Chat between both the clients through servers.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    int num2;

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Use the server's IP address here

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    // Input a number from the user
    printf("Enter a number: ");
    scanf("%d", &num2);

    // Send the number to the server
    send(client_socket, &num2, sizeof(int), 0);

    // Close the socket
    close(client_socket);

    return 0;
}
