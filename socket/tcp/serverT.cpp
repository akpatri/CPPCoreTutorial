/*
============================================================
TCP SERVER SOCKET FLOW
============================================================

socket()   -> create tcp socket
bind()     -> attach socket to ip:port
listen()   -> wait for clients
accept()   -> accept client connection
recv()     -> receive data
send()     -> send data
shutdown() -> stop communication
close()    -> release socket

------------------------------------------------------------
IMPORTANT:
- TCP = connection oriented
- server needs fixed ip:port using bind()
- accept() returns NEW socket for client
- server socket keeps listening for more clients
============================================================
*/

#include <iostream>
#include <cstring>

#include <unistd.h>
#include <winsock2.h>  //#include <arpa/inet.h>
#include <ws2tcpip.h>  //#include <sys/socket.h>

using namespace std;

/**===========================================================
1.int socket(int domain, int type, int protocol)
--------------------------------------------------------------
create socket endpoint
===========================================================

parameter:
    domain:
        AF_INET  -> IPv4
        AF_INET6 -> IPv6

    type:
        SOCK_STREAM -> TCP socket

    protocol:
        0 -> auto select protocol

returns:
    - socket fd on success
    - -1 on failure
===========================================================*/
void explain_socket()
{
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);

    if (serverFd == -1)
    {
        perror("socket failed");
        return;
    }

    cout << "socket created" << endl;

    close(serverFd);
}

/**===========================================================
2.struct sockaddr_in
--------------------------------------------------------------
stores ip + port information
===========================================================

important fields:
    sin_family -> address family
    sin_port   -> port number
    sin_addr   -> ip address
===========================================================*/
void explain_sockaddr()
{
    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;

    serverAddr.sin_port = htons(8080);
    // htons() -> host to network short

    serverAddr.sin_addr.s_addr = INADDR_ANY;
    // accept connection from any ip
}

/**===========================================================
3.int bind(int sockfd, sockaddr *addr, socklen_t len)
--------------------------------------------------------------
attach socket to ip:port
===========================================================

parameter:
    sockfd -> socket fd
    addr   -> address structure
    len    -> structure size

returns:
    0  -> success
    -1 -> failure
===========================================================*/
void explain_bind()
{
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    int result = bind(
        serverFd,
        (sockaddr *)&serverAddr,
        sizeof(serverAddr));

    if (result == -1)
    {
        perror("bind failed");
        close(serverFd);
        return;
    }

    cout << "bind success" << endl;

    close(serverFd);
}

/**===========================================================
4.int listen(int sockfd, int backlog)
--------------------------------------------------------------
put socket into listening mode
===========================================================

parameter:
    sockfd  -> server socket fd
    backlog -> waiting queue size

returns:
    0  -> success
    -1 -> failure
===========================================================*/
void explain_listen()
{
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverFd,
         (sockaddr *)&serverAddr,
         sizeof(serverAddr));

    int result = listen(serverFd, 5);

    if (result == -1)
    {
        perror("listen failed");
        close(serverFd);
        return;
    }

    cout << "server listening..." << endl;

    close(serverFd);
}

/**===========================================================
5.int accept(int sockfd, sockaddr *addr, socklen_t *len)
--------------------------------------------------------------
accept client connection
===========================================================

parameter:
    sockfd -> listening socket
    addr   -> client address
    len    -> client structure size

returns:
    - new client socket fd
    - -1 on failure

IMPORTANT:
    - accept() blocks until client connects
    - returned socket is used for communication
===========================================================*/
void explain_accept()
{
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverFd,
         (sockaddr *)&serverAddr,
         sizeof(serverAddr));

    listen(serverFd, 5);

    sockaddr_in clientAddr{};
    socklen_t clientLen = sizeof(clientAddr);

    int clientFd = accept(
        serverFd,
        (sockaddr *)&clientAddr,
        &clientLen);

    if (clientFd == -1)
    {
        perror("accept failed");
        close(serverFd);
        return;
    }

    cout << "client connected" << endl;

    close(clientFd);
    close(serverFd);
}

/**===========================================================
6.ssize_t recv()
--------------------------------------------------------------
receive data from client
===========================================================

syntax:
    recv(sockfd, buffer, size, flags)

returns:
    >0 -> bytes received
    0  -> client disconnected
    -1 -> failure
===========================================================*/
void explain_recv()
{
    int clientFd = 0;

    char buffer[1024];

    ssize_t bytes = recv(
        clientFd,
        buffer,
        sizeof(buffer) - 1,
        0);

    if (bytes > 0)
    {
        buffer[bytes] = '\0';

        cout << "received: " << buffer << endl;
    }
}

/**===========================================================
7.ssize_t send()
--------------------------------------------------------------
send data to client
===========================================================

syntax:
    send(sockfd, data, size, flags)

returns:
    - bytes sent
    - -1 on failure
===========================================================*/
void explain_send()
{
    int clientFd = 0;

    const char *msg = "hello client";

    send(
        clientFd,
        msg,
        strlen(msg),
        0);
}

/**===========================================================
8.int shutdown(int sockfd, int how)
--------------------------------------------------------------
disable communication
===========================================================

parameter:
    SHUT_RD   -> stop reading
    SHUT_WR   -> stop writing
    SHUT_RDWR -> stop both
    for windows:
    SD_RECEIVE  // like SHUT_RD
    SD_SEND     // like SHUT_WR
    SD_BOTH     // like SHUT_RDWR
===========================================================*/
void explain_shutdown()
{
    int clientFd = 0;

    shutdown(clientFd, SD_BOTH);

    close(clientFd);
}

/**===========================================================
9.COMPLETE TCP SERVER
--------------------------------------------------------------
minimal working tcp server
===========================================================*/
void tcp_server()
{
    // create TCP socket
    int serverFd = socket(AF_INET, SOCK_STREAM, 0); // IPv4 TCP socket

    if (serverFd == -1)
    {
        perror("socket");
        return;
    }

    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET; // use IPv4

    serverAddr.sin_port = htons(8080); // port number

    serverAddr.sin_addr.s_addr = INADDR_ANY;
    // accept connection from any network interface

    // bind socket with ip:port
    if (bind(serverFd,
             (sockaddr *)&serverAddr, // convert to sockaddr*
             sizeof(serverAddr)) == -1)
    {
        perror("bind");

        close(serverFd); // release socket

        return;
    }

    // start listening for clients
    if (listen(serverFd, 5) == -1) // queue size = 5
    {
        perror("listen");

        close(serverFd);

        return;
    }

    cout << "waiting for client..." << endl;

    sockaddr_in clientAddr{};
    socklen_t clientLen = sizeof(clientAddr);

    // accept client connection
    int clientFd = accept(
        serverFd,
        (sockaddr *)&clientAddr, // store client info
        &clientLen);

    if (clientFd == -1)
    {
        perror("accept");

        close(serverFd);

        return;
    }

    cout << "client connected" << endl;

    char buffer[1024];

    // receive data from client
    ssize_t bytes = recv(
        clientFd,
        buffer,
        sizeof(buffer) - 1, // leave space for '\0'
        0);

    if (bytes > 0)
    {
        buffer[bytes] = '\0'; // convert to string

        cout << "client: " << buffer << endl;
    }

    // send reply to client
    const char *reply = "hello from server";

    send(
        clientFd,
        reply,
        strlen(reply), // send exact bytes
        0);

    // stop read/write communication
    shutdown(clientFd, SD_BOTH);

    close(clientFd); // close client socket

    close(serverFd); // close server socket
}

/**===========================================================
main()
===========================================================*/
int main()
{
    tcp_server();

    return 0;
}