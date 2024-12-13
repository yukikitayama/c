# Networking

Overview
- Most networked applications have 2 separate programs; server and client
- Create programs that act as servers and programs that act as clients

TCP (Transmission Control Protocol)
- A standard that defines how to establish and maintain a network conversation through which application programs can exchange data
- TCP works with the Internet Protocol (IP) which defines how computers send packets of data to each other
- TCP and IP are the basic rules defining the Internet
- TCP is a connection that is established and maintained until the application programs at each end have finished exchanging messages (**connection-oriented protocol**)
  - A connection between source and destination is created by TCP before transmitting the data, and keeps the connection alive until the communication is no longer active.

Client/server model
- Typically the clients communicate with servers by using the TCP/IP protocol suite
- Client-server model is one of the central ideas of network computing
- Connection is over a local area network (LAN) or wide-area network (WAN, e.g., the Internet)
- Once the server has fulfilled the client's request, the connection is terminated
- A special server called a **daemon** may be activated just to await client requests.
- **Internet Browser** is a client program which sends a request to the Web Server to get one HTML webpage.
- **Web Server** is a server program which keeps waiting for requests from Internet Browsers. Once get request, picks up a requested HTML page and sends it back to that Browser.

Servers
- Iterative server
- Concurrent server

Socket
- **Sockets** are the virtual endpoints of any kind of network communications done between two computers
- **Socket programming** is a way of connecting two nodes on a network to communicate with each other
- One socket (node) listens on a particular port at an address.
  - Another socket reaches out to the other to form a connection
  - Server forms the listener socket, and client reaches out.
- **All network communication goes through a socket**.

Step for server
- Create a socket with `socket()` system call
- Bind the socket to an address using `bind()` system call
- Listen for connections with `listen()` system call
- Accept a connection with `accept()` system call
  - This blocks the connection until a client connects with the server
- Send and receive data using `read()/recv`, `write()/send` system calls

Step for client
- Create a socket with `socket()` system call
- Connect the socket to the address of the server using `connect()` system call
- Send and receive data using `read()/recv`, `write()/send` system calls

Include files for socket
- `<sys/types.h>` definitions of data types in socket calls
- `<sys/socket.h>` definitions of structures for sockets (create, accept, listen, ...)
- `<netinet/in.h>` constants and structures for internet domain addresses
- `<netdb.h>` definitions of structure hostent
- `<arpa/inet.h>` definitions of `in_addr` structure.
- `<unistd.h>` read, write, close

Port
- A computer might need to run several server programs at once
- **Each server uses a different port** to prevent the different conversations from getting confused.
  - Different ports are used for different network services.
- We can use port number between 1024 and 65535
- `getservbyname()` gets port number
- `getservbyport()` gets service name
- `struct servent`

IP address function
- `int inet_aton(const char *strptr, struct in_addr *addrptr)`
  - Converts the specified string in the Internet standard dot notation to a network address and stores the address in the structure.
- `in_addr_t inet_addr(const char *strptr)`
  - Converts the specified string in the Internet standard dot notation to an integer value suitable for use as an Internet address
- `char *inet_ntoa(struct in_addr inaddr)`
  - Converts the specified Internet host address to a string in the Internet standard dot notation.

Structures for socket
- Socket address structures are important for network program.
- Most socket functions require a pointer to a socket address structure
  - We allocate address structures and pass pointers to the structure for socket functions
- Socket function fills in the contents of the structure
- **Always pass the structures by reference and pass the size of the structure**
- When a socket function fills in a structure, **the length is also passed by reference and the value can be updated by the function**.
- **Always set the structure variables to NULL, otherwise get unexpected junk values in structure**.
- `struct sockaddr` structure to hold the socket information and passed in socket functions
  - `sa_family` can be `AF_INET`, `AF_UNIX`, `AF_NS`, `AF_IMPLINK`
  - Typically `AF_INET` as the internet-based applications
  - `sa_data` is protocol-specific address, using `sockaddr_in`
- `struct sockaddr_in` structure as reference to socket's elements
- `struct in_addr` structure for the 32 bit netid/hostid
- `struct hostent` structure keeps the host information

Functions for socket
- `socket()` and `accept()` return handles (**file descriptor**)
- Sockets have addresses associated with the handles.
- **Sockets must be in the correct state to perform input or output**.
- Need to include `<sys/types.h>`, `<sys/socket.h>`, and `<unistd.h>`
- `bind()` only server
- `connect()` only client
- `int socket(int family, int type, int protocol);` specifies the type of communication protocol
  - **Returns a socket descriptor to be used in later system calls**.
  - `family` is `AF_INET` for IPv4 protocols and `AF_INETc` for IP6 protocols
  - `type` is usually `SOCK_STREAM` as a stream socket, or `SOCK_DGRAM` as a datagram socket.
  - `protocol` is `IPPROTO_TCP` for TCP transport protocol, `IPPROTO_UDP` for UDP, `IPPROTO_SCTP` for SCTP
- `int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);` is optional to change options in the file descriptor (**sockfd**)
  - Useful for reuse of address and port
- `int connect(int sockfd, struct sockaddr *serv_addr, int addrlen);` establishes a connection between TCP client and TCP server
  - `serve_addr` is a pointer to `struct sockaddr` that contains destination IP address and port
  - `addrlen` is `sizeof(struct sockaddr)`
  - Returns 0 if success connect, -1 if error
- `int bind(int sockfd, struct sockaddr *my_addr, int addrlen)`
  - Tells OS which port the server program is going to use (**binding the port**) with a given IP address
  - Once bind, any program on the network can connect and client program and server program will be linked
  - `my_addr` is a pointer to `struct sockaddr`. 
  - `server.sin_port = 0;` **0 value for port number means the system assign a random port number**.
  - `server.sin_addr.s_addr = INADDR_ANY;`, `INADDR_ANY` for IP address means the server's IP address will be assigned automatically
  - `addrlen` is `sizeof(struct sockaddr)`
  - Returns 0 for success, -1 for error
- `int listen(int sockfd, int backlog)`
  - `backlog` is the max number of allowed connections. Defines a queue length.
    - e.g., 10 length queue means 10 clients can try to connect to the server at once, and 11th client will be told server is busy.
  - **`listen()` is called only by a server**.
- `int accept(int sockfd, struct sockaddr *cliaddr, socklen_t *addrlen);`
  - This call waits until a client contacts the server, and returns the socket descriptor that you can use to hold a conversation on.
  - **All read-write operations will be done on this descriptor to communicate with the client**.
  - `cliaddr` is pointer to `struct sockaddr` of client IP address and port
  - `addrlen` is `sizeof(struct sockaddr)`
  - Returns non-negative descriptor on success, -1 on error
- `int recv(int sockfd, void *buf, int len, unsigned int flags);`
  - Receives data over stream sockets or connected datagram sockets
  - `buf` is buffer to read the information inet_aton
  - `len` is maximum length of the buffer
  - `flags` is set to 0
  - **Returns the number of bytes read into the buffer, otherwise return -1 on error**.
  - `recvfrom()` for unconnected datagram sockets
- `int write(int fildes, const void *buf, int nbyte);`
  - `fildes` is socket descriptor returned by socket function
  - `buf` is a pointer to the data you want to send
  - `nbyte` is the number of bytes to be written
  - Returns the number of bytes written to the file associated with `fildes`, -1 if error.
- `int send(int sockfd, const void *msg, int len, int flags);`
  - Send data over stream sockets or connected datagram sockets
  - `msg` is a pointer to the data you want to send
  - `len` is length of the data you want to send (in bytes)
  - `flags` is set to 0.
  - Returns the number of bytes sent out, -1 on error.
  - `sendto()` for unconnected datagram sockets
- `int read(int fildes, const void *buf, int nbyte);`
  - Read `nbyte` bytes from the file associated with buffer `fildes` into the buffer `buf`
  - `fildes` socket descriptor by socket function
  - `buf` is pointer to buffer to read the information into
  - `nbyte` the number of bytes to read
  - Returns the number of bytes written, -1 if error
- `int close(int sockfd);` cloes the communication between client and server
  - Returns 0 on success, -1 on error
- `int shutdown(int sockfd, int how);`
  - Close communication with more control
  - `how`
    - `0` Receiving is not allowed
    - `1` Sending is not allowed
    - `2` Sending and receiving are not allowed. `2` means the same as `close()`
  - Returns 0 on success, -1 on error
