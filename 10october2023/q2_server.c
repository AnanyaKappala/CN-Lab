/* 2 clients send a number to server and server will check whether if it's a perfect number or not and display the
result on each client respectively.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>

bool is_perfect(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

int main() {
    int serverSocket, client1Socket, client2Socket;
    struct sockaddr_in serverAddr, client1Addr, client2Addr;
    socklen_t addr_size;
    int num1, num2;
    
    // Create server socket
    serverSocket = socket(PF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(7891);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the server socket
    bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    // Listen for incoming connections
    listen(serverSocket, 5);
    addr_size = sizeof(client1Addr);

    // Accept connections from client-1 and client-2
    client1Socket = accept(serverSocket, (struct sockaddr *)&client1Addr, &addr_size);
    addr_size = sizeof(client2Addr);
    client2Socket = accept(serverSocket, (struct sockaddr *)&client2Addr, &addr_size);

    // Receive numbers from client-1 and client-2
    recv(client1Socket, &num1, sizeof(num1), 0);
    recv(client2Socket, &num2, sizeof(num2), 0);

    // Check if the received numbers are perfect and send the result back
    if (is_perfect(num1)) {
        send(client1Socket, "Perfect", 8, 0);
    } else {
        send(client1Socket, "Not Perfect", 12, 0);
    }

    if (is_perfect(num2)) {
        send(client2Socket, "Perfect", 8, 0);
    } else {
        send(client2Socket, "Not Perfect", 12, 0);
    }

    // Close sockets
    close(client1Socket);
    close(client2Socket);
    close(serverSocket);

    return 0;
}
