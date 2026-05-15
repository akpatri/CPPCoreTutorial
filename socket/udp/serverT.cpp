/*
============================================================
UDP SERVER SOCKET FLOW
============================================================

socket()   -> create udp socket
bind()     -> attach socket to ip:port
recvfrom() -> receive datagram from client
sendto()   -> send datagram to client
close()    -> release socket

------------------------------------------------------------
IMPORTANT:
- UDP = connectionless
- no listen()
- no accept()
- data sent as packets(datagram)
- faster but unreliable compared to TCP
============================================================
*/

#include <iostream>
#include <cstring>

#include <unistd.h>
#include <winsock2.h> 
#include <ws2tcpip.h> 

using namespace std;


/**===========================================================
1.int socket(int domain, int type, int protocol)
--------------------------------------------------------------
create UDP socket
===========================================================

parameter:
    domain:
        AF_INET  -> IPv4
        AF_INET6 -> IPv6

    type:
        SOCK_DGRAM -> UDP socket

    protocol:
        0 -> auto select protocol

returns:
    - socket fd on success
    - -1 on failure
===========================================================*/
void explain_socket()
{
    int serverFd = socket(AF_INET, SOCK_DGRAM, 0);
    // create IPv4 UDP socket

    if(serverFd == -1)
    {
        perror("socket failed");

        return;
    }

    cout << "UDP socket created" << endl;

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

    serverAddr.sin_family = AF_INET; // IPv4

    serverAddr.sin_port = htons(9090); // port number

    serverAddr.sin_addr.s_addr = INADDR_ANY;
    // accept packets from any ip
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
    int serverFd = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9090);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    int result = bind(
        serverFd,
        (sockaddr*)&serverAddr, // convert type
        sizeof(serverAddr)
    );

    if(result == -1)
    {
        perror("bind failed");

        close(serverFd);

        return;
    }

    cout << "bind success" << endl;

    close(serverFd);
}


/**===========================================================
4.ssize_t recvfrom()
--------------------------------------------------------------
receive datagram from client
===========================================================

syntax:
    recvfrom(sockfd, buffer, size, flags,
             sockaddr*, socklen_t*)

returns:
    >0 -> bytes received
    -1 -> failure

IMPORTANT:
    - no connection required
    - client address also received
===========================================================*/
void explain_recvfrom()
{
    int serverFd = socket(AF_INET, SOCK_DGRAM, 0);

    char buffer[1024];

    sockaddr_in clientAddr{};
    socklen_t clientLen = sizeof(clientAddr);

    ssize_t bytes = recvfrom(
        serverFd,
        buffer,
        sizeof(buffer)-1, // leave space for '\0'
        0,
        (sockaddr*)&clientAddr, // store client info
        &clientLen
    );

    if(bytes > 0)
    {
        buffer[bytes] = '\0';

        cout << "received: " << buffer << endl;
    }

    close(serverFd);
}


/**===========================================================
5.ssize_t sendto()
--------------------------------------------------------------
send datagram to client
===========================================================

syntax:
    sendto(sockfd, data, size, flags,
           sockaddr*, socklen_t)

returns:
    - bytes sent
    - -1 on failure
===========================================================*/
void explain_sendto()
{
    int serverFd = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in clientAddr{};

    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(9090);

    inet_pton(
        AF_INET,
        "127.0.0.1", // localhost ip
        &clientAddr.sin_addr
    );

    const char *msg = "hello udp client";

    sendto(
        serverFd,
        msg,
        strlen(msg), // send exact bytes
        0,
        (sockaddr*)&clientAddr,
        sizeof(clientAddr)
    );

    close(serverFd);
}


/**===========================================================
6.COMPLETE UDP SERVER
--------------------------------------------------------------
minimal working udp server
===========================================================*/
void udp_server()
{
    // create UDP socket
    int serverFd = socket(AF_INET, SOCK_DGRAM, 0);

    if(serverFd == -1)
    {
        perror("socket");

        return;
    }


    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET; // IPv4

    serverAddr.sin_port = htons(9090); // server port

    serverAddr.sin_addr.s_addr = INADDR_ANY;
    // receive from any network interface


    // bind socket with ip:port
    if(bind(serverFd,
            (sockaddr*)&serverAddr,
            sizeof(serverAddr)) == -1)
    {
        perror("bind");

        close(serverFd);

        return;
    }

    cout << "UDP server waiting..." << endl;


    char buffer[1024];

    sockaddr_in clientAddr{};
    socklen_t clientLen = sizeof(clientAddr);


    // receive packet from client
    ssize_t bytes = recvfrom(
        serverFd,
        buffer,
        sizeof(buffer)-1,
        0,
        (sockaddr*)&clientAddr, // store client info
        &clientLen
    );

    if(bytes == -1)
    {
        perror("recvfrom");

        close(serverFd);

        return;
    }


    buffer[bytes] = '\0';

    cout << "client: " << buffer << endl;


    // reply message
    const char *reply = "hello from udp server";


    // send packet back to client
    sendto(
        serverFd,
        reply,
        strlen(reply),
        0,
        (sockaddr*)&clientAddr,
        clientLen
    );

    cout << "reply sent" << endl;


    close(serverFd); // release socket
}


/**===========================================================
main()
===========================================================*/
int main()
{
    udp_server();

    return 0;
}