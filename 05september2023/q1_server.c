/* WAP where the client sends 2 nos to the server. The server finds out their square roots and returns the result 
back to the client.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 256

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error in socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in binding");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 10) == 0) {
        printf("Listening...\n");
    } else {
        perror("Error in listening");
        exit(1);
    }

    addr_size = sizeof(new_addr);
    new_socket = accept(server_socket, (struct sockaddr*)&new_addr, &addr_size); // Accept connection

    // Receive data from client
    recv(new_socket, buffer, BUFFER_SIZE, 0);
    printf("Received from client: %s\n", buffer);

    // Parse and calculate square roots
    char *token = strtok(buffer, ",");
    double num1 = atof(token);
    token = strtok(NULL, ",");
    double num2 = atof(token);

    double sqrt1 = sqrt(num1);
    double sqrt2 = sqrt(num2);

    // Prepare the response
    snprintf(response, BUFFER_SIZE, "Square root of %.2lf is %.2lf, and square root of %.2lf is %.2lf", num1, sqrt1, num2, sqrt2);

    // Send the response back to the client
    send(new_socket, response, strlen(response), 0);
    printf("Response sent to client: %s\n", response);

    close(new_socket);
    close(server_socket);

    return 0;
}
