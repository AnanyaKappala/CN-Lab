/* WAP where client will send a number and server will check whether it is an armstrong number or not and display.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Send the number to the server
    send(clientSocket, &num, sizeof(num), 0);

    // Receive the result from the server
    bool isArmstrongNum;
    recv(clientSocket, &isArmstrongNum, sizeof(isArmstrongNum), 0);

    if (isArmstrongNum) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    close(clientSocket);
    return 0;
}
