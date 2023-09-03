/* WAP to send any 2 nos. from client to server and perform all arithematic operations in server and display it.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize;

    // Create server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("Error in socket creation");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Port number
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error in binding");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == 0) {
        printf("Server listening...\n");
    } else {
        perror("Error in listening");
        exit(1);
    }

    addrSize = sizeof(clientAddr);

    // Accept a connection from the client
    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrSize);
    if (clientSocket < 0) {
        perror("Error in accepting connection");
        exit(1);
    }

    // Receive two numbers from the client
    int num1, num2;
    recv(clientSocket, &num1, sizeof(num1), 0);
    recv(clientSocket, &num2, sizeof(num2), 0);

    // Perform arithmetic operations
    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    float quotient = (float)num1 / num2;

    // Send the results back to the client
    send(clientSocket, &sum, sizeof(sum), 0);
    send(clientSocket, &difference, sizeof(difference), 0);
    send(clientSocket, &product, sizeof(product), 0);
    send(clientSocket, &quotient, sizeof(quotient), 0);

    close(serverSocket);
    return 0;
}
