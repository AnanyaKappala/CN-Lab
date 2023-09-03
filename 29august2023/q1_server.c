/* WAP where client will send a number and server will check whether it is an armstrong number or not and display.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <netinet/in.h>

// Function to check if a number is an Armstrong number
bool isArmstrong(int num) {
    int originalNum, remainder, result = 0;
    originalNum = num;

    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += remainder * remainder * remainder;
        originalNum /= 10;
    }

    return result == num;
}

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

    // Receive the number from the client
    int num;
    recv(clientSocket, &num, sizeof(num), 0);

    // Check if the received number is an Armstrong number
    bool isArmstrongNum = isArmstrong(num);

    // Send the result back to the client
    send(clientSocket, &isArmstrongNum, sizeof(isArmstrongNum), 0);

    close(serverSocket);
    return 0;
}
