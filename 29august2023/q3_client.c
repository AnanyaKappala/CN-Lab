/* WAP to send your name from client and server will find the count of vowels and display.*/
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

    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);

    // Send the name to the server
    send(clientSocket, name, sizeof(name), 0);

    int vowelCount;
    // Receive the vowel count from the server
    recv(clientSocket, &vowelCount, sizeof(vowelCount), 0);

    printf("The number of vowels in your name is: %d\n", vowelCount);

    close(clientSocket);
    return 0;
}
