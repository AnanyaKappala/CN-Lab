/*Client sends two numbers to server and server will display it's sum.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[BUFFER_SIZE];
    int num1, num2, sum;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error in socket");
        exit(1);
    }

    // Server socket settings
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = PORT;
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error in binding");
        exit(1);
    }

    // Listen
    if (listen(server_socket, 10) == 0) {
        printf("Listening...\n");
    } else {
        printf("Error in listening\n");
        exit(1);
    }

    addr_size = sizeof(new_addr);
    new_socket = accept(server_socket, (struct sockaddr *)&new_addr, &addr_size); // Accept connection

    // Receive first number from client
    recv(new_socket, buffer, BUFFER_SIZE, 0);
    num1 = atoi(buffer);
    printf("Received number 1: %d\n", num1);

    // Receive second number from client
    recv(new_socket, buffer, BUFFER_SIZE, 0);
    num2 = atoi(buffer);
    printf("Received number 2: %d\n", num2);

    // Calculate the sum
    sum = num1 + num2;
    printf("Sum: %d\n", sum);

    close(new_socket);
    close(server_socket);

    return 0;
}
