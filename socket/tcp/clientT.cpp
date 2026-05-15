/*
============================================================
TCP CLIENT SOCKET FLOW
============================================================

socket()   -> create tcp socket
connect()  -> connect to server
send()     -> send data
recv()     -> receive data
shutdown() -> stop communication
close()    -> release socket

------------------------------------------------------------
IMPORTANT:
- TCP = connection oriented
- client must connect before send/recv
- server ip + port required
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
create TCP socket
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
    int clientFd = socket(AF_INET, SOCK_STREAM, 0);
    // create IPv4 TCP socket

    if(clientFd == -1)
    {
        perror("socket failed");

        return;
    }

    cout << "TCP socket created" << endl;

    close(clientFd);
}


/**===========================================================
2.struct sockaddr_in
--------------------------------------------------------------
stores server ip + port
===========================================================

important fields:
    sin_family -> address family
    sin_port   -> port number
    sin_addr   -> ip address
===========================================================*/
void explain_sockaddr()
{
    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET; // IPv4

    serverAddr.sin_port = htons(8080); // server port


    inet_pton(
        AF_INET,
        "127.0.0.1", // localhost ip
        &serverAddr.sin_addr
    );
}


/**===========================================================
3.int connect(int sockfd, sockaddr *addr, socklen_t len)
--------------------------------------------------------------
connect client to server
===========================================================

parameter:
    sockfd -> client socket fd
    addr   -> server address
    len    -> structure size

returns:
    0  -> success
    -1 -> failure
===========================================================*/
void explain_connect()
{
    int clientFd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;

    serverAddr.sin_port = htons(8080);


    inet_pton(
        AF_INET,
        "127.0.0.1",
        &serverAddr.sin_addr
    );


    int result = connect(
        clientFd,
        (sockaddr*)&serverAddr, // server info
        sizeof(serverAddr)
    );

    if(result == -1)
    {
        perror("connect failed");

        close(clientFd);

        return;
    }

    cout << "connected to server" << endl;

    close(clientFd);
}


/**===========================================================
4.ssize_t send()
--------------------------------------------------------------
send data to server
===========================================================

syntax:
    send(sockfd, data, size, flags)

returns:
    - bytes sent
    - -1 on failure
===========================================================*/
void explain_send()
{
    int clientFd = socket(AF_INET, SOCK_STREAM, 0);

    const char *msg = "hello server";

    send(
        clientFd,
        msg,
        strlen(msg), // send exact bytes
        0
    );

    close(clientFd);
}


/**===========================================================
5.ssize_t recv()
--------------------------------------------------------------
receive data from server
===========================================================

syntax:
    recv(sockfd, buffer, size, flags)

returns:
    >0 -> bytes received
    0  -> server disconnected
    -1 -> failure
===========================================================*/
void explain_recv()
{
    int clientFd = socket(AF_INET, SOCK_STREAM, 0);

    char buffer[1024];

    ssize_t bytes = recv(
        clientFd,
        buffer,
        sizeof(buffer)-1,
        0
    );

    if(bytes > 0)
    {
        buffer[bytes] = '\0';

        cout << "server: " << buffer << endl;
    }

    close(clientFd);
}


/**===========================================================
6.int shutdown(int sockfd, int how)
--------------------------------------------------------------
disable communication
===========================================================

parameter:
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
    int clientFd = socket(AF_INET, SOCK_STREAM, 0);

    shutdown(clientFd,SD_BOTH);

    close(clientFd);
}


/**===========================================================
7.COMPLETE TCP CLIENT
--------------------------------------------------------------
minimal working tcp client
===========================================================*/
void tcp_client()
{
    // create TCP socket
    int clientFd = socket(AF_INET, SOCK_STREAM, 0);

    if(clientFd == -1)
    {
        perror("socket");

        return;
    }


    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET; // IPv4

    serverAddr.sin_port = htons(8080); // server port


    inet_pton(
        AF_INET,
        "127.0.0.1", // localhost server ip
        &serverAddr.sin_addr
    );


    // connect with server
    if(connect(clientFd,
               (sockaddr*)&serverAddr,
               sizeof(serverAddr)) == -1)
    {
        perror("connect");

        close(clientFd);

        return;
    }

    cout << "connected to server" << endl;


    // message for server
    const char *msg = "hello from tcp client";


    // send data to server
    send(
        clientFd,
        msg,
        strlen(msg),
        0
    );


    char buffer[1024];


    // receive reply from server
    ssize_t bytes = recv(
        clientFd,
        buffer,
        sizeof(buffer)-1,
        0
    );

    if(bytes == -1)
    {
        perror("recv");

        close(clientFd);

        return;
    }


    buffer[bytes] = '\0';

    cout << "server: " << buffer << endl;


    // stop communication
    shutdown(clientFd, SD_BOTH);

    close(clientFd); // release socket
}


/**===========================================================
main()
===========================================================*/
int main()
{
    tcp_client();

    return 0;
}