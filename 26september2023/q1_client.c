/*Send name to the client and, server will receive it and display it.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

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

    // Server socket settings
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address (localhost in this example)

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in connection");
        exit(1);
    }

    // Send data to the server
    printf("Enter a name: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    send(client_socket, buffer, strlen(buffer), 0);

    close(client_socket);

    return 0;
}
