/* WAP to send your name from client and server will find the count of vowels and display.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

int countVowels(char *str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        // Check if the character is a vowel (both uppercase and lowercase)
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
    }
    return count;
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

    char name[100];
    // Receive the name from the client
    recv(clientSocket, name, sizeof(name), 0);

    // Count vowels in the received name
    int vowelCount = countVowels(name);

    // Send the vowel count back to the client
    send(clientSocket, &vowelCount, sizeof(vowelCount), 0);

    close(serverSocket);
    return 0;
}
