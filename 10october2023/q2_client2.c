/* 2 clients send a number to server and server will check whether if it's a perfect number or not and display the
result on each client respectively.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    int num2;
    
    // Create client socket
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    printf("Enter a number: ");
    scanf("%d", &num2);

    // Send the number to the server
    send(clientSocket, &num2, sizeof(num2), 0);

    char response[50];
    recv(clientSocket, response, sizeof(response), 0);
    printf("From Server: %s\n", response);

    // Close the client socket
    close(clientSocket);

    return 0;
}
