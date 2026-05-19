/*
================================================================
MODULAR TCP CLIENT
================================================================

OVERVIEW:
----------------------------------------------------------------
This program demonstrates complete TCP client-side socket
programming using a clean modular design.

The client:
----------------------------------------------------------------
1. Creates TCP socket
2. Connects to remote TCP server
3. Sends message to server
4. Receives server response
5. Gracefully terminates connection
6. Releases socket resources

================================================================
TCP CLIENT COMMUNICATION FLOW
================================================================

    socket()
        ↓
    create TCP client socket

    connect()
        ↓
    establish TCP connection with server

    send()
        ↓
    transmit data to server

    recv()
        ↓
    receive response from server

    shutdown()
        ↓
    disable send/receive communication

    close()/closesocket()
        ↓
    release socket descriptor and OS resources

================================================================
IMPORTANT TCP CONCEPTS
================================================================

TCP:
----------------------------------------------------------------
- connection-oriented protocol
- reliable communication
- ordered packet delivery
- error checking and retransmission
- full duplex communication

CLIENT REQUIREMENTS:
----------------------------------------------------------------
- server IP address required
- server port required
- successful connect() required before send()/recv()

SOCKET DESCRIPTOR:
----------------------------------------------------------------
clientFd:
    integer returned by socket()

Used for:
----------------------------------------------------------------
- connect()
- send()
- recv()
- shutdown()
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
    8080

Used to identify:
    specific server application/process

================================================================
IMPORTANT NETWORK CONVERSIONS
================================================================

htons():
----------------------------------------------------------------
Host TO Network Short

Converts:
    CPU-native port number
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
Uses:
    Winsock API

Required:
    WSAStartup()
    WSACleanup()

LINUX:
----------------------------------------------------------------
Uses:
    POSIX socket API

No special initialization required.

================================================================
EXAMPLE COMMUNICATION
================================================================

CLIENT:
    "hello from tcp client"

SERVER:
    "hello from server"

================================================================
*/

#include <iostream> // cout, cerr
#include <string>   // std::string
#include <cstring>  // strlen()

#ifdef _WIN32

#include <winsock2.h> // socket(), connect(), send(), recv()
#include <ws2tcpip.h> // inet_pton(), sockaddr_in

#pragma comment(lib, "ws2_32.lib") // link Winsock library

#define CLOSE_SOCKET closesocket // Windows socket close function

#else

#include <unistd.h> // close()
#include <arpa/inet.h> // htons(), inet_pton()
#include <sys/socket.h> // socket(), connect(), send(), recv()

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
CREATE TCP SOCKET
---------------------------------------------------------------
Creates IPv4 TCP client socket.
===============================================================*/
int createSocket()
{
    int clientFd = socket(
        AF_INET,      // IPv4 address family
        SOCK_STREAM,  // TCP socket
        0);           // auto-select TCP protocol

    if (clientFd == -1) // socket creation failure
    {
        perror("socket");

        return -1;
    }

    cout << "[OK] TCP socket created" << endl;

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
    sockaddr_in serverAddr{}; // server address structure

    serverAddr.sin_family = AF_INET; // IPv4

    serverAddr.sin_port = htons(port); // host -> network byte order

    inet_pton(
        AF_INET,                  // IPv4 conversion
        ip.c_str(),               // readable IP string
        &serverAddr.sin_addr);    // binary IPv4 destination

    return serverAddr; // return configured server address
}

/*===============================================================
CONNECT TO SERVER
---------------------------------------------------------------
Establishes TCP connection with server.
===============================================================*/
bool connectToServer(
    int clientFd,
    sockaddr_in &serverAddr)
{
    int result = connect(
        clientFd,                  // client socket descriptor
        (sockaddr *)&serverAddr,  // server address information
        sizeof(serverAddr));      // structure size

    if (result == -1) // connection failure
    {
        perror("connect");

        return false;
    }

    cout << "[OK] connected to server" << endl;

    return true;
}

/*===============================================================
SEND MESSAGE
---------------------------------------------------------------
Transmits data to connected server.
===============================================================*/
bool writeMessage(
    int clientFd,
    const string &message)
{
    ssize_t sentBytes = send(
        clientFd,               // connected client socket
        message.c_str(),        // convert string -> const char*
        message.size(),         // number of bytes to send
        0);                     // normal blocking send

    if (sentBytes == -1) // send failure
    {
        perror("send");

        return false;
    }

    return true;
}

/*===============================================================
RECEIVE MESSAGE
---------------------------------------------------------------
Receives server response.
===============================================================*/
string readMessage(int clientFd)
{
    char buffer[1024]; // receive buffer

    ssize_t bytes = recv(
        clientFd,              // connected socket
        buffer,                // receive buffer
        sizeof(buffer) - 1,   // leave space for '\0'
        0);                    // normal blocking receive

    if (bytes <= 0) // recv failure or disconnect
    {
        perror("recv");

        return "";
    }

    buffer[bytes] = '\0'; // manually terminate C-string

    return string(buffer); // convert char[] -> string
}

/*===============================================================
SHUTDOWN CONNECTION
---------------------------------------------------------------
Gracefully stops socket communication.
===============================================================*/
void shutdownConnection(int clientFd)
{
#ifdef _WIN32

    shutdown(clientFd, SD_BOTH); // disable send + receive

#else

    shutdown(clientFd, SHUT_RDWR); // disable send + receive

#endif

    CLOSE_SOCKET(clientFd); // release socket descriptor

    cout << "[OK] connection closed" << endl;
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
TCP CLIENT
---------------------------------------------------------------
Complete TCP client workflow.
===============================================================*/
void tcpClient()
{
    if (!initializeWinsock()) // initialize networking library
    {
        return;
    }

    int clientFd = createSocket(); // create TCP socket

    if (clientFd == -1)
    {
        cleanupWinsock();

        return;
    }

    sockaddr_in serverAddr =
        createServerAddress(
            "127.0.0.1", // localhost server IP
            8080);       // server port

    if (!connectToServer(clientFd, serverAddr)) // establish connection
    {
        shutdownConnection(clientFd);

        cleanupWinsock();

        return;
    }

    writeMessage(
        clientFd,
        "hello from tcp client"); // send message to server

    string serverReply =
        readMessage(clientFd); // receive server response

    if (!serverReply.empty())
    {
        cout << "server: " << serverReply << endl;
    }

    shutdownConnection(clientFd); // terminate communication

    cleanupWinsock(); // cleanup networking library
}

/*===============================================================
MAIN
===============================================================*/
int main()
{
    tcpClient(); // start TCP client

    return 0;
}