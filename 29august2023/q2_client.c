/* WAP to send any 2 nos. from client to server and perform all arithematic operations in server and display it.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;

    // Create client socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        perror("Error in socket creation");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Port number
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error in connection");
        exit(1);
    }

    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Send the numbers to the server
    send(clientSocket, &num1, sizeof(num1), 0);
    send(clientSocket, &num2, sizeof(num2), 0);

    // Receive the results from the server
    int sum, difference, product;
    float quotient;
    recv(clientSocket, &sum, sizeof(sum), 0);
    recv(clientSocket, &difference, sizeof(difference), 0);
    recv(clientSocket, &product, sizeof(product), 0);
    recv(clientSocket, &quotient, sizeof(quotient), 0);

    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Quotient: %.2f\n", quotient);

    close(clientSocket);
    return 0;
}
