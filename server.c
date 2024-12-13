#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

short socketCreate(void) {
    short hSocket = 0;
    printf("Create the socket\n");
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
    // Server
    int socket_desc = 0;
    char message[100] = {0};
    const char *pMessage = "hello";
    
    // Variables to hold Client information
    int sock = 0, clientLen = 0;
    struct sockaddr_in client;
    char client_message[200] = {0};
    clientLen = sizeof(struct sockaddr_in);

    // Server creates socket
    socket_desc = socketCreate();
    if (socket_desc == -1) {
        printf("Could not create socket\n");
        return 1;
    }
    printf("Socket created\n");

    // Server binds
    if (bindCreatedSocket(socket_desc) < 0) {
        perror("bind failed\n");
        return 1;
    }
    printf("bind done\n");

    // Server listens
    listen(socket_desc, 3);

    // Server accepts
    while (1) {
        printf("Waiting for incoming connections...\n");

        // Server accepts connection from a client
        sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&clientLen);
        if (sock < 0) {
            perror("accept failed");
            return 1;
        }
        printf("Connection accepted\n");

        // Set up for data exchange
        memset(client_message, '\0', sizeof client_message);
        memset(message, '\0', sizeof message);

        // Server receives from a client
        if (recv(sock, client_message, 200, 0) < 0) {
            printf("recv failed");
            break;
        }
        printf("Server received client message: %s\n", client_message);

        // Server sends a validation message to client
        // Success if a client sent the message that server expects
        if (strncmp(pMessage, client_message, 5) == 0) {
            strcpy(message, "Validation success\n");
        }
        else {
            strcpy(message, "Invalid message\n");
        }
        if (send(sock, message, strlen(message), 0) < 0) {
            printf("Send failed");
            return 1;
        }

        close(sock);
        sleep(1);
    }

    return 0;
}
