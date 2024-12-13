#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

short socketCreate(void) {
    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int socketConnect(int hSocket) {
    int iRetval = -1;
    int ServerPort = 12345;

    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);

    iRetval = connect(hSocket, (struct sockaddr *)&remote, sizeof(struct sockaddr));
    return iRetval;
}

int socketSend(int hSocket, char* Rqst, short lenRqst) {
    int shortRetval = -1;

    // Set option
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;
    if (setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0) {
        printf("Time Out\n");
        return -1;
    }

    shortRetval = send(hSocket, Rqst, lenRqst, 0);
    
    return shortRetval;
}

int socketReceive(int hSocket, char* Rsp, short RvcSize) {
    int shortRetval = -1;

    // Set option
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;
    if (setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) < 0) {
        printf("Time Out\n");
        return -1;
    }

    shortRetval = recv(hSocket, Rsp, RvcSize, 0);
    printf("Client received the server message: %s\n", Rsp);

    return shortRetval;
}

int main(void) {
    // Client
    int hSocket = 0, read_size = 0;
    // Server side information
    // struct sockaddr_in server;
    // Message from client to server
    char sendToServer[100] = {0};
    // Message from server to client
    char server_reply[200] = {0};

    // Create client socket
    hSocket = socketCreate();
    if (hSocket == -1) {
        printf("Could not create socket\n");
        return 1;
    }
    printf("Socket is created\n");

    // Connect to server
    if (socketConnect(hSocket) < 0) {
        perror("connect failed\n");
        return 1;
    }
    printf("Connected with server\n");

    // Send message to server
    printf("Enter the message: ");
    fgets(sendToServer, 100, stdin);
    socketSend(hSocket, sendToServer, strlen(sendToServer));

    // Receive message from server
    read_size = socketReceive(hSocket, server_reply, 200);
    printf("Message from server: %s\n\n", server_reply);

    close(hSocket);

    return 0;
}

