/*
================================================================
MODULAR UDP CLIENT
================================================================

OVERVIEW:
----------------------------------------------------------------
This program demonstrates complete UDP client-side socket
programming using a clean modular design.

The client:
----------------------------------------------------------------
1. Creates UDP socket
2. Builds server address structure
3. Sends datagram to server
4. Receives datagram from server
5. Releases socket resources

================================================================
UDP CLIENT COMMUNICATION FLOW
================================================================

    socket()
        ↓
    create UDP socket

    sendto()
        ↓
    send datagram to server IP:PORT

    recvfrom()
        ↓
    receive datagram from server

    close()/closesocket()
        ↓
    release socket resources

================================================================
IMPORTANT UDP CONCEPTS
================================================================

UDP:
----------------------------------------------------------------
- connectionless protocol
- no connection establishment
- no TCP handshake
- no delivery guarantee
- no packet ordering guarantee
- lightweight and fast
- lower overhead than TCP

UDP DOES NOT USE:
----------------------------------------------------------------
- connect()
- listen()
- accept()

COMMUNICATION:
----------------------------------------------------------------
Client directly sends packet to:
    server IP + server PORT

Each UDP packet is called:
    datagram

================================================================
SOCKET DESCRIPTOR
================================================================

clientFd:
----------------------------------------------------------------
integer returned by socket()

Used for:
----------------------------------------------------------------
- sendto()
- recvfrom()
- close()

================================================================
ADDRESSING INFORMATION
================================================================

IPv4 ADDRESS:
----------------------------------------------------------------
Example:
    127.0.0.1

Meaning:
    localhost / same machine

PORT NUMBER:
----------------------------------------------------------------
Example:
    9090

Identifies:
    specific UDP server process

================================================================
IMPORTANT NETWORK CONVERSIONS
================================================================

htons():
----------------------------------------------------------------
Host TO Network Short

Converts:
    host port number
            ↓
    network byte order (big-endian)

inet_pton():
----------------------------------------------------------------
Presentation TO Network

Converts:
    readable IP string
            ↓
    binary IPv4 address

================================================================
PLATFORM SUPPORT
================================================================

WINDOWS:
----------------------------------------------------------------
Uses Winsock API

Required:
    WSAStartup()
    WSACleanup()

LINUX:
----------------------------------------------------------------
Uses POSIX socket API

No special initialization required.

================================================================
EXAMPLE COMMUNICATION
================================================================

CLIENT:
    "hello from udp client"

SERVER:
    "hello from udp server"

================================================================
*/

#include <iostream> // cout, cerr
#include <string>   // std::string
#include <cstring>  // strlen()

#ifdef _WIN32

#include <winsock2.h> // socket(), sendto(), recvfrom()
#include <ws2tcpip.h> // inet_pton(), sockaddr_in

#pragma comment(lib, "ws2_32.lib") // link Winsock library

#define CLOSE_SOCKET closesocket // Windows socket close function

#else

#include <unistd.h> // close()
#include <arpa/inet.h> // htons(), inet_pton()
#include <sys/socket.h> // socket(), sendto(), recvfrom()

#define CLOSE_SOCKET close // Linux socket close function

#endif
#include <cstdint> // provides fixed-size integers like uint16_t and uint32_t

using namespace std;

/*===============================================================
INITIALIZE WINSOCK
---------------------------------------------------------------
Required only on Windows before using sockets.
===============================================================*/
bool initializeWinsock()
{
#ifdef _WIN32

    WSADATA wsa; // Winsock startup information

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) // initialize Winsock library
    {
        cerr << "WSAStartup failed" << endl;

        return false;
    }

#endif

    return true;
}

/*===============================================================
CREATE UDP SOCKET
---------------------------------------------------------------
Creates IPv4 UDP socket.
===============================================================*/
int createSocket()
{
    int clientFd = socket(
        AF_INET,      // IPv4 address family
        SOCK_DGRAM,   // UDP socket type
        0);           // auto-select UDP protocol

    if (clientFd == -1) // socket creation failure
    {
        perror("socket");

        return -1;
    }

    cout << "[OK] UDP socket created" << endl;

    return clientFd; // return socket descriptor
}

/*===============================================================
CREATE SERVER ADDRESS
---------------------------------------------------------------
Creates IPv4 server address structure.
===============================================================*/
sockaddr_in createServerAddress(
    const string &ip,
    uint16_t port)
{
    sockaddr_in serverAddr{}; // IPv4 server address structure

    serverAddr.sin_family = AF_INET; // use IPv4 addressing

    serverAddr.sin_port = htons(port); // convert port -> network byte order

    inet_pton(
        AF_INET,                 // IPv4 conversion
        ip.c_str(),              // readable IPv4 string
        &serverAddr.sin_addr);   // binary IPv4 destination

    return serverAddr; // return configured server address
}

/*===============================================================
SEND UDP DATAGRAM
---------------------------------------------------------------
sendto() sends packet directly to server.
===============================================================*/
bool sendMessage(
    int clientFd,
    const string &message,
    sockaddr_in &serverAddr)
{
    ssize_t sentBytes = sendto(
        clientFd,                     // UDP socket descriptor
        message.c_str(),              // message bytes
        message.size(),               // number of bytes to send
        0,                            // normal send mode
        (sockaddr *)&serverAddr,      // destination server address
        sizeof(serverAddr));          // address structure size

    if (sentBytes == -1) // send failure
    {
        perror("sendto");

        return false;
    }

    cout << "[OK] datagram sent" << endl;

    return true;
}

/*===============================================================
RECEIVE UDP DATAGRAM
---------------------------------------------------------------
recvfrom() receives packet from server.
===============================================================*/
string receiveMessage(
    int clientFd,
    sockaddr_in &serverAddr)
{
    char buffer[1024]; // receive buffer

    socklen_t serverLen = sizeof(serverAddr); // server structure size

    ssize_t bytes = recvfrom(
        clientFd,                    // UDP socket descriptor
        buffer,                      // destination receive buffer
        sizeof(buffer) - 1,          // leave space for '\0'
        0,                           // normal blocking receive
        (sockaddr *)&serverAddr,     // stores sender information
        &serverLen);                 // sender structure size

    if (bytes <= 0) // receive failure
    {
        perror("recvfrom");

        return "";
    }

    buffer[bytes] = '\0'; // manually terminate C-string

    return string(buffer); // convert char[] -> string
}

/*===============================================================
CLOSE UDP SOCKET
===============================================================*/
void closeSocket(int clientFd)
{
    CLOSE_SOCKET(clientFd); // release socket descriptor

    cout << "[OK] socket closed" << endl;
}

/*===============================================================
CLEANUP WINSOCK
===============================================================*/
void cleanupWinsock()
{
#ifdef _WIN32

    WSACleanup(); // release Winsock resources

#endif
}

/*===============================================================
UDP CLIENT
---------------------------------------------------------------
Complete UDP client workflow.
===============================================================*/
void udpClient()
{
    if (!initializeWinsock()) // initialize networking library
    {
        return;
    }

    int clientFd = createSocket(); // create UDP socket

    if (clientFd == -1)
    {
        cleanupWinsock();

        return;
    }

    sockaddr_in serverAddr =
        createServerAddress(
            "127.0.0.1", // localhost server IP
            9090);       // UDP server port

    sendMessage(
        clientFd,
        "hello from udp client",
        serverAddr); // send UDP datagram

    string serverReply =
        receiveMessage(
            clientFd,
            serverAddr); // receive server response

    if (!serverReply.empty())
    {
        cout << "server: " << serverReply << endl;
    }

    closeSocket(clientFd); // release UDP socket

    cleanupWinsock(); // cleanup networking resources
}

/*===============================================================
MAIN
===============================================================*/
int main()
{
    udpClient(); // start UDP client

    return 0;
}