/*
============================================================
UDP CLIENT SOCKET FLOW
============================================================

socket()   -> create udp socket
sendto()   -> send datagram to server
recvfrom() -> receive datagram from server
close()    -> release socket

------------------------------------------------------------
IMPORTANT:
- UDP = connectionless
- no connect()
- no listen()
- no accept()
- client directly sends packet to server ip:port
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
    int clientFd = socket(AF_INET, SOCK_DGRAM, 0);
    // create UDP socket

    if(clientFd == -1)
    {
        perror("socket failed");

        return;
    }

    cout << "UDP socket created" << endl;

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

    serverAddr.sin_port = htons(9090); // server port


    inet_pton(
        AF_INET,
        "127.0.0.1", // localhost ip
        &serverAddr.sin_addr
    );
}


/**===========================================================
3.ssize_t sendto()
--------------------------------------------------------------
send datagram to server
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
    int clientFd = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(9090);

    inet_pton(
        AF_INET,
        "127.0.0.1",
        &serverAddr.sin_addr
    );

    const char *msg = "hello server";

    sendto(
        clientFd,
        msg,
        strlen(msg), // send exact bytes
        0,
        (sockaddr*)&serverAddr,
        sizeof(serverAddr)
    );

    close(clientFd);
}


/**===========================================================
4.ssize_t recvfrom()
--------------------------------------------------------------
receive datagram from server
===========================================================

syntax:
    recvfrom(sockfd, buffer, size, flags,
             sockaddr*, socklen_t*)

returns:
    >0 -> bytes received
    -1 -> failure
===========================================================*/
void explain_recvfrom()
{
    int clientFd = socket(AF_INET, SOCK_DGRAM, 0);

    char buffer[1024];

    sockaddr_in serverAddr{};
    socklen_t serverLen = sizeof(serverAddr);

    ssize_t bytes = recvfrom(
        clientFd,
        buffer,
        sizeof(buffer)-1,
        0,
        (sockaddr*)&serverAddr,
        &serverLen
    );

    if(bytes > 0)
    {
        buffer[bytes] = '\0';

        cout << "server: " << buffer << endl;
    }

    close(clientFd);
}


/**===========================================================
5.COMPLETE UDP CLIENT
--------------------------------------------------------------
minimal working udp client
===========================================================*/
void udp_client()
{
    // create UDP socket
    int clientFd = socket(AF_INET, SOCK_DGRAM, 0);

    if(clientFd == -1)
    {
        perror("socket");

        return;
    }


    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET; // IPv4

    serverAddr.sin_port = htons(9090); // server port


    inet_pton(
        AF_INET,
        "127.0.0.1", // localhost server ip
        &serverAddr.sin_addr
    );


    // message to server
    const char *msg = "hello from udp client";


    // send packet to server
    sendto(
        clientFd,
        msg,
        strlen(msg),
        0,
        (sockaddr*)&serverAddr,
        sizeof(serverAddr)
    );

    cout << "message sent" << endl;


    char buffer[1024];

    socklen_t serverLen = sizeof(serverAddr);


    // receive reply from server
    ssize_t bytes = recvfrom(
        clientFd,
        buffer,
        sizeof(buffer)-1,
        0,
        (sockaddr*)&serverAddr,
        &serverLen
    );

    if(bytes == -1)
    {
        perror("recvfrom");

        close(clientFd);

        return;
    }


    buffer[bytes] = '\0';

    cout << "server: " << buffer << endl;


    close(clientFd); // release socket
}


/**===========================================================
main()
===========================================================*/
int main()
{
    udp_client();

    return 0;
}