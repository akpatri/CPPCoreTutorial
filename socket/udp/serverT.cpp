/*
================================================================
MODULAR UDP SERVER
================================================================

OVERVIEW:
----------------------------------------------------------------
This program demonstrates complete UDP server-side socket
programming using a clean modular design.

The server:
----------------------------------------------------------------
1. Creates UDP socket
2. Binds socket to IP:PORT
3. Waits for client datagram
4. Receives packet from client
5. Sends response packet to client
6. Releases socket resources

================================================================
UDP SERVER COMMUNICATION FLOW
================================================================

    socket()
        ↓
    create UDP socket

    bind()
        ↓
    attach socket to IP:PORT

    recvfrom()
        ↓
    receive client datagram

    sendto()
        ↓
    send reply datagram

    close()/closesocket()
        ↓
    release socket resources

================================================================
IMPORTANT UDP CONCEPTS
================================================================

UDP:
----------------------------------------------------------------
- connectionless protocol
- no TCP handshake
- no connection establishment
- no delivery guarantee
- no packet ordering guarantee
- low overhead and fast communication

UDP DOES NOT USE:
----------------------------------------------------------------
- listen()
- accept()
- connect()

DATAGRAM:
----------------------------------------------------------------
UDP data packet is called:
    datagram

Each packet contains:
----------------------------------------------------------------
- payload data
- source address
- destination address

================================================================
SOCKET DESCRIPTOR
================================================================

serverFd:
----------------------------------------------------------------
integer returned by socket()

Used for:
----------------------------------------------------------------
- bind()
- recvfrom()
- sendto()
- close()

================================================================
ADDRESSING INFORMATION
================================================================

IPv4 ADDRESS:
----------------------------------------------------------------
INADDR_ANY

Meaning:
    receive packets from all network interfaces

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

#include <winsock2.h> // socket(), bind(), sendto(), recvfrom()
#include <ws2tcpip.h> // sockaddr_in, inet_pton()

#pragma comment(lib, "ws2_32.lib") // link Winsock library

#define CLOSE_SOCKET closesocket // Windows socket close function

#else

#include <unistd.h> // close()
#include <arpa/inet.h> // htons(), inet_pton()
#include <sys/socket.h> // socket(), bind(), sendto(), recvfrom()

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

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) // initialize Winsock
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
    int serverFd = socket(
        AF_INET,      // IPv4 address family
        SOCK_DGRAM,   // UDP socket type
        0);           // auto-select UDP protocol

    if (serverFd == -1) // socket creation failure
    {
        perror("socket");

        return -1;
    }

    cout << "[OK] UDP socket created" << endl;

    return serverFd; // return socket descriptor
}

/*===============================================================
CREATE SERVER ADDRESS
---------------------------------------------------------------
Creates IPv4 server address structure.
===============================================================*/
sockaddr_in createServerAddress(uint16_t port)
{
    sockaddr_in serverAddr{}; // IPv4 server address structure

    serverAddr.sin_family = AF_INET; // IPv4 addressing

    serverAddr.sin_port = htons(port); // host -> network byte order

    serverAddr.sin_addr.s_addr = INADDR_ANY; // receive from any network interface

    return serverAddr; // return configured server address
}

/*===============================================================
BIND SOCKET
---------------------------------------------------------------
Attaches socket to server IP:PORT.
===============================================================*/
bool bindSocket(
    int serverFd,
    sockaddr_in &serverAddr)
{
    int result = bind(
        serverFd,                  // UDP socket descriptor
        (sockaddr *)&serverAddr,   // server address structure
        sizeof(serverAddr));       // structure size

    if (result == -1) // bind failure
    {
        perror("bind");

        return false;
    }

    cout << "[OK] bind success" << endl;

    return true;
}

/*===============================================================
RECEIVE UDP DATAGRAM
---------------------------------------------------------------
recvfrom() receives packet from client.
===============================================================*/
string receiveMessage(
    int serverFd,
    sockaddr_in &clientAddr,
    socklen_t &clientLen)
{
    char buffer[1024]; // receive buffer

    ssize_t bytes = recvfrom(
        serverFd,                   // UDP server socket
        buffer,                     // receive buffer
        sizeof(buffer) - 1,         // leave space for '\0'
        0,                          // normal blocking receive
        (sockaddr *)&clientAddr,    // stores sender address
        &clientLen);                // sender address size

    if (bytes <= 0) // receive failure
    {
        perror("recvfrom");

        return "";
    }

    buffer[bytes] = '\0'; // manually terminate C-string

    return string(buffer); // convert char[] -> string
}

/*===============================================================
SEND UDP DATAGRAM
---------------------------------------------------------------
sendto() sends reply packet to client.
===============================================================*/
bool sendMessage(
    int serverFd,
    const string &message,
    sockaddr_in &clientAddr,
    socklen_t clientLen)
{
    ssize_t sentBytes = sendto(
        serverFd,                   // UDP server socket
        message.c_str(),            // message bytes
        message.size(),             // number of bytes to send
        0,                          // normal send mode
        (sockaddr *)&clientAddr,    // destination client address
        clientLen);                 // destination structure size

    if (sentBytes == -1) // send failure
    {
        perror("sendto");

        return false;
    }

    cout << "[OK] reply sent" << endl;

    return true;
}

/*===============================================================
CLOSE SOCKET
===============================================================*/
void closeSocket(int serverFd)
{
    CLOSE_SOCKET(serverFd); // release UDP socket descriptor

    cout << "[OK] server socket closed" << endl;
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
UDP SERVER
---------------------------------------------------------------
Complete UDP server workflow.
===============================================================*/
void udpServer()
{
    if (!initializeWinsock()) // initialize networking library
    {
        return;
    }

    int serverFd = createSocket(); // create UDP socket

    if (serverFd == -1)
    {
        cleanupWinsock();

        return;
    }

    sockaddr_in serverAddr =
        createServerAddress(9090); // configure UDP server address

    if (!bindSocket(serverFd, serverAddr)) // bind socket to port
    {
        closeSocket(serverFd);

        cleanupWinsock();

        return;
    }

    cout << "\nUDP server waiting...\n" << endl;

    sockaddr_in clientAddr{}; // stores client address information

    socklen_t clientLen = sizeof(clientAddr); // client structure size

    string clientMessage =
        receiveMessage(
            serverFd,
            clientAddr,
            clientLen); // receive client datagram

    if (!clientMessage.empty())
    {
        cout << "client: " << clientMessage << endl;
    }

    sendMessage(
        serverFd,
        "hello from udp server",
        clientAddr,
        clientLen); // send reply datagram

    closeSocket(serverFd); // release socket resources

    cleanupWinsock(); // cleanup networking library
}

/*===============================================================
MAIN
===============================================================*/
int main()
{
    udpServer(); // start UDP server

    return 0;
}