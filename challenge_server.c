#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

short socketCreate(void) {
    short hSocket;
    printf("Created socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int bindCreatedSocket(int hSocket) {
    int iRetval = -1;
    int clientPort = 12345;

    struct sockaddr_in remote = {0};
    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(clientPort);

    iRetval = bind(hSocket, (struct sockaddr *)&remote, sizeof(remote));
    return iRetval;
}

int main() {
    // Server info
    int server_socket = 0, accept_socket = 0;
    char message[100] = {0};
    memset(message, '\0', sizeof message);

    // Client info
    int clientLen = 0;
    struct sockaddr_in client;
    clientLen = sizeof(struct sockaddr_in);
    char client_message[200] = {0};
    memset(client_message, '\0', sizeof client_message);

    // Create socket
    server_socket = socketCreate();
    if (server_socket == -1) {
        printf("Could not create socket");
        return 1;
    }
    printf("Socket created\n");

    // Bind socket
    if (bindCreatedSocket(server_socket) < 0) {
        perror("bind failed");
        return 1;
    }
    printf("Bind done\n");

    // Listen
    listen(server_socket, 3);
    printf("Waiting for incoming connections...\n");

    // Accept connection from client
    accept_socket = accept(server_socket, (struct sockaddr *)&client, (socklen_t *)&clientLen);
    if (accept_socket < 0) {
        perror("Accept failed");
        return 1;
    }
    printf("Connection accepted\n");

    // Receive data
    if (recv(accept_socket, client_message, 200, 0) < 0) {
        printf("recv failed\n");
    }
    printf("Received message from client: %s\n", client_message);

    // Process the received data
    // Convert string to integer
    int i = atoi(client_message);
    i--;
    // Convert integre to string and save
    sprintf(message, "%d", i);

    // Close to switch clients
    close(accept_socket);

    printf("Waiting for incoming connections...\n");

    // Accept 2nd client
    accept_socket = accept(server_socket, (struct sockaddr *)&client, (socklen_t *)&clientLen);
    if (accept_socket < 0) {
        perror("accept failed");
        return 1;
    }
    printf("Connection accepted\n");

    // Send data to 2nd client
    if (send(accept_socket, message, strlen(message), 0) < 0) {
        printf("Send failed");
        return 1;
    }

    return 0;
}

