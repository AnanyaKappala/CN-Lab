/* Create a TCP socket with 2 clients sending a number to server respectively and server will check whether it's a 
prime number or not and display on each client.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
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

    // Check if the received numbers are prime and send the result back
    if (is_prime(num1)) {
        send(client1Socket, "Prime", 6, 0);
    } else {
        send(client1Socket, "Not Prime", 10, 0);
    }

    if (is_prime(num2)) {
        send(client2Socket, "Prime", 6, 0);
    } else {
        send(client2Socket, "Not Prime", 10, 0);
    }

    // Close sockets
    close(client1Socket);
    close(client2Socket);
    close(serverSocket);

    return 0;
}
