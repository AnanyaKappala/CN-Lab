/* WAP where the client sends 2 nos to the server. The server finds out their square roots and returns the result 
back to the client.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 256

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error in socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in connection");
        exit(1);
    }

    // Input two numbers
    printf("Enter two numbers separated by a comma (e.g., 4.0, 9.0): ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Send data to server
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive and print server response
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", buffer);

    close(client_socket);

    return 0;
}
