/* WAP to connect two clients and server and perform the following.
a. Client 1 will send a no, client 2 will send a no, server will calculate the product and display on client 1.
b. Chat between both the clients through servers.*/
// Client-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char message[1024];

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

    while (1) {
        // Input a message from the user
        printf("Enter a message (type 'exit' to quit): ");
        fgets(message, sizeof(message), stdin);

        // Send the message to the server
        send(client_socket, message, strlen(message), 0);

        // Check if the client wants to exit
        if (strcmp(message, "exit\n") == 0) {
            break;
        }

        // Receive a message from the server and display it
        memset(message, 0, sizeof(message));
        recv(client_socket, message, sizeof(message), 0);
        printf("Server: %s\n", message);
    }

    // Close the socket
    close(client_socket);

    return 0;
}
