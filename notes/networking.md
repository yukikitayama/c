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

Steps
- Create a new socket
- Attach a local address to a socket (bind)
- Announce willingness to accept connections (listen)
- Block caller until a connection request arrives (accept)
- Attempt to establish a connection (connect)
- Send data (send)
- Receive data (receive)
- Release the connection (close)


Step for server

Step for client

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
- 

Structures for socket
-
- `sockaddr`
- `sockaddr_in`
- `in_addr`
- `hostent`

Functions for socket
- `bind()` only server
- `connect()` only client
- `socket()`
- `connect()`
- `bind()`
- `listen()`
- `accept()`
- `recv()`
- `write()`
- `send()`
- `read()`
- `close()`
- `shutdown()`


REVIEW FROM THE SOCKET API VIDEO