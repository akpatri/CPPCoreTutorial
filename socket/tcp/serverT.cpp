/*
====================================================================
MODULAR TCP SERVER - SUMMARY
====================================================================

This program implements a simple modular TCP server using sockets.

--------------------------------------------------------------------
FEATURES
--------------------------------------------------------------------

1. Cross-platform support
   - Windows  -> Winsock2
   - Linux    -> POSIX sockets

2. Modular socket architecture
   - createSocket()
   - bindSocket()
   - startListening()
   - establishConnection()
   - readMessage()
   - writeMessage()
   - shutdownConnection()

3. Reusable design
   - avoids duplicated code
   - easier debugging
   - cleaner networking flow
   - scalable for advanced servers

--------------------------------------------------------------------
TCP SERVER FLOW
--------------------------------------------------------------------

socket()
    ↓
bind()
    ↓
listen()
    ↓
accept()
    ↓
recv()
    ↓
send()
    ↓
shutdown()
    ↓
close()

--------------------------------------------------------------------
IMPORTANT TCP CONCEPTS
--------------------------------------------------------------------

1. TCP is connection-oriented
   - reliable communication
   - ordered packet delivery
   - error checking

2. Server socket vs client socket
   - server socket:
         used only for listening

   - client socket:
         returned by accept()
         used for communication

3. bind()
   - attaches socket to fixed IP + PORT

4. listen()
   - puts socket into passive mode
   - waits for incoming clients

5. accept()
   - blocks until client connects
   - creates NEW communication socket

6. recv()
   - receives bytes from client

7. send()
   - sends bytes to client

8. shutdown()
   - disables communication gracefully

--------------------------------------------------------------------
EXAMPLE
--------------------------------------------------------------------

Server Port:
    8080

Client sends:
    "hello server"

Server replies:
    "hello from server"

--------------------------------------------------------------------
FUTURE IMPROVEMENTS
--------------------------------------------------------------------

1. Multi-client server using threads
2. Non-blocking sockets
3. select()/poll()/epoll()
4. TCP client implementation
5. HTTP web server
6. File transfer server
7. Chat server
8. OOP socket wrapper
9. Async reactor architecture

====================================================================
*/

#include <iostream> // cout, cerr, endl
#include <cstring>  // C-style string utilities

#ifdef _WIN32 // compile Windows-specific code

#include <winsock2.h> // Windows socket API
#include <ws2tcpip.h> // sockaddr_in, inet functions

#pragma comment(lib, "ws2_32.lib") // link Winsock library automatically

#define CLOSE_SOCKET closesocket // Windows socket close function

#else // compile Linux/Unix-specific code

#include <unistd.h>     // close()
#include <arpa/inet.h>  // sockaddr_in, htons(), INADDR_ANY
#include <sys/socket.h> // socket(), bind(), listen(), accept(), recv(), send()

#define CLOSE_SOCKET close // Linux socket close function

#endif

using namespace std; // avoid std:: prefix

/*===========================================================
WINDOWS SOCKET STARTUP
===========================================================*/
bool initializeWinsock()
{
#ifdef _WIN32

    WSADATA wsa;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        cerr << "WSAStartup failed" << endl;
        return false;
    }

#endif

    return true;
}

/*===========================================================
CREATE TCP SOCKET
--------------------------------------------------------------
Creates and returns an IPv4 TCP socket file descriptor.
===========================================================*/
int createSocket()
{
    int serverFd = socket(AF_INET, SOCK_STREAM, 0);

    // AF_INET     -> IPv4 address family
    // SOCK_STREAM -> TCP socket
    // 0           -> auto-select TCP protocol

    if (serverFd == -1)
    {
        perror("socket");

        return -1;
        // return failure
    }

    cout << "[OK] socket created" << endl;

    return serverFd;
    // return valid socket file descriptor
}

/*===========================================================
CREATE SERVER ADDRESS
--------------------------------------------------------------
Creates and returns IPv4 server address structure
containing IP address + port information.
===========================================================*/
sockaddr_in createServerAddress(int port)
{
    sockaddr_in serverAddr{};

    serverAddr.sin_family = AF_INET;
    // use IPv4 address family

    serverAddr.sin_port = htons(port);
    // convert port to network byte order

    serverAddr.sin_addr.s_addr = INADDR_ANY;
    // accept connection from any network interface

    return serverAddr;
    // return fully configured server address
}

/*===========================================================
BIND SOCKET TO IP:PORT
--------------------------------------------------------------
Attaches server socket to specific IP address and port.
===========================================================*/
bool bindSocket(int serverFd, sockaddr_in &serverAddr)
{
    // bind socket with IP address + port number
    int result = bind(
        serverFd, // server socket file descriptor

        (sockaddr *)&serverAddr, // convert sockaddr_in*
                                 // to generic sockaddr*

        sizeof(serverAddr)); // size of address structure

    // check bind failure
    if (result == -1)
    {
        perror("bind"); // print system bind error

        return false; // indicate bind failure
    }

    cout << "[OK] bind success" << endl;
    // socket successfully attached to IP:PORT

    return true; // indicate bind success
}

/*===========================================================
START LISTENING
--------------------------------------------------------------
Put server socket into listening mode so clients
can connect to the server.
===========================================================*/
bool startListening(int serverFd, int backlog = 5)
{
    // listen()
    // serverFd -> server socket file descriptor
    // backlog  -> maximum pending connection queue size
    // returns -1 on failure
    if (listen(serverFd, backlog) == -1)
    {
        // print system-generated listen error message
        perror("listen");

        // indicate listen operation failed
        return false;
    }

    // server successfully entered listening state
    cout << "[OK] server listening..." << endl;

    // indicate listen operation success
    return true;
}

/*===========================================================
ESTABLISH CLIENT CONNECTION
--------------------------------------------------------------
accept() waits for client and creates NEW socket
for communication.
===========================================================*/
int establishConnection(int serverFd)
{
    sockaddr_in clientAddr{}; // stores client IP + port information

    socklen_t clientLen = sizeof(clientAddr); // size of client address structure

    int clientFd = accept(
        serverFd, // listening server socket

        (sockaddr *)&clientAddr, // stores connected client information

        &clientLen); // structure size (input/output parameter)

    if (clientFd == -1) // check accept() failure
    {
        perror("accept"); // print system-generated error

        return -1; // return invalid socket descriptor
    }

    cout << "[OK] client connected" << endl; // client successfully connected

    return clientFd; // return NEW socket used for recv() and send()
}

/*===========================================================
READ MESSAGE FROM CLIENT
--------------------------------------------------------------
recv() receives bytes from connected TCP client.
===========================================================*/
string readMessage(int clientFd)
{
    char buffer[1024]; // raw byte buffer for incoming client data

    // NOTE:
    // read() can also be used on Linux sockets because
    // sockets behave like file descriptors.
    //
    // recv() is preferred because it supports socket flags.

    ssize_t bytes = recv(
        clientFd,           // connected client socket
        buffer,             // memory buffer for received data
        sizeof(buffer) - 1, // leave 1 byte space for '\0'
        0);                 // 0 = normal blocking receive mode

    // recv() returns:
    // >0 -> bytes received
    //  0 -> client disconnected
    // -1 -> receive error

    if (bytes <= 0) // check disconnect or recv failure
    {
        perror("recv"); // print recv() system error

        return ""; // return empty string on failure
    }

    buffer[bytes] = '\0'; // manually add null terminator

    return string(buffer); // convert char buffer to C++ string
}

/*===========================================================
WRITE MESSAGE TO CLIENT
--------------------------------------------------------------
send() transmits bytes to connected TCP client.
===========================================================*/
bool writeMessage(int clientFd, const string &message)
{
    // NOTE:
    // write() can also be used on Linux sockets because
    // sockets behave like file descriptors.
    //
    // send() is preferred because it supports socket flags.

    ssize_t sentBytes = send(
        clientFd,        // connected client socket
        message.c_str(), // convert C++ string to const char*
        message.size(),  // number of bytes to send
        0);              // 0 = normal blocking send mode

    // send() returns:
    // >=0 -> bytes successfully sent
    // -1  -> send failed

    if (sentBytes == -1) // check send failure
    {
        perror("send"); // print send() system error

        return false; // indicate send failure
    }

    return true; // indicate send success
}

/*===========================================================
SHUTDOWN CONNECTION
--------------------------------------------------------------
shutdown() disables socket communication gracefully.

IMPORTANT:
--------------------------------------------------------------
shutdown()
    -> stops send/receive operations

close()/closesocket()
    -> releases socket descriptor from OS

Both are commonly used together.
===========================================================*/
void shutdownConnection(int clientFd)
{
#ifdef _WIN32

    shutdown(clientFd, SD_BOTH); // disable both send + receive on Windows

#else

    shutdown(clientFd, SHUT_RDWR); // disable both send + receive on Linux

#endif

    CLOSE_SOCKET(clientFd); // release socket descriptor and free OS resources

    cout << "[OK] connection closed" << endl; // connection successfully terminated
}

/*===========================================================
CLOSE SERVER SOCKET
--------------------------------------------------------------
Closes server socket and releases networking resources.
===========================================================*/
void closeServer(int serverFd)
{
    CLOSE_SOCKET(serverFd); // close listening server socket descriptor

#ifdef _WIN32

    WSACleanup(); // cleanup Winsock library resources on Windows

#endif

    cout << "[OK] server stopped" << endl; // server successfully terminated
}

/*===========================================================
PRINT SOCKET DIAGNOSTIC INFORMATION
--------------------------------------------------------------
Displays runtime information about connected client.
===========================================================*/
void printDiagnosticInfo(int clientFd, sockaddr_in &clientAddr)
{
    char clientIp[INET_ADDRSTRLEN]; // buffer to store readable IPv4 string like "192.168.1.10"

    inet_ntop(
        AF_INET,              // convert IPv4 binary address to readable text format
        &clientAddr.sin_addr, // client IPv4 address stored by accept()
        clientIp,             // destination buffer for converted IP string
        sizeof(clientIp));    // maximum writable buffer size

    cout << "\n========== DIAGNOSTIC INFO ==========" << endl; // diagnostic section header

    cout << "client socket fd : " << clientFd << endl; // socket used for recv() and send()

    cout << "client ip        : " << clientIp << endl; // readable client IPv4 address

    cout << "client port      : "
         << ntohs(clientAddr.sin_port)
         << endl; // convert network byte order port -> CPU native format

    cout << "address family   : AF_INET (IPv4)" << endl; // communication uses IPv4

    cout << "socket type      : SOCK_STREAM (TCP)" << endl; // reliable TCP stream socket

    cout << "connection state : CONNECTED" << endl; // TCP connection successfully established

    cout << "=====================================\n"
         << endl; // diagnostic section footer
}

/*===========================================================
TCP SERVER
--------------------------------------------------------------
Complete TCP server workflow:

1. initialize Winsock (Windows only)
2. create TCP socket
3. create server address
4. bind socket to IP:PORT
5. start listening
6. accept client connection
7. receive client message
8. send reply
9. shutdown client connection
10. close server socket
===========================================================*/
void tcpServer()
{
    if (!initializeWinsock()) // initialize Winsock library on Windows
    {
        return; // stop server if Winsock initialization fails
    }

    // 1. create TCP socket
    int serverFd = createSocket();

    if (serverFd == -1) // check socket creation failure
    {
        return; // stop server if socket creation fails
    }

    // 2. create IPv4 server address structure
    sockaddr_in serverAddr = createServerAddress(8080);

    // 3. bind socket with IP address + port
    if (!bindSocket(serverFd, serverAddr))
    {
        closeServer(serverFd); // release server socket resources

        return; // stop server if bind fails
    }

    // 4. put socket into listening mode
    if (!startListening(serverFd))
    {
        closeServer(serverFd); // close server socket on failure

        return; // stop server if listen fails
    }

    cout << "\nwaiting for client...\n"
         << endl; // server now waiting for connections

    // 5. accept incoming client connection
    int clientFd = establishConnection(serverFd);

    if (clientFd == -1) // check accept() failure
    {
        closeServer(serverFd); // close listening socket

        return; // stop server if client connection fails
    }

    // 6. receive message from connected client
    string clientMessage = readMessage(clientFd);

    if (!clientMessage.empty()) // check if valid message received
    {
        cout << "client: " << clientMessage << endl; // print received client message
    }

    // 7. send response message to client
    writeMessage(clientFd, "hello from server");

    // 8. gracefully stop client communication
    shutdownConnection(clientFd);

    // 9. close server socket and cleanup resources
    closeServer(serverFd);
}

/*===========================================================
MAIN
--------------------------------------------------------------
Program entry point.
===========================================================*/
int main()
{
    tcpServer(); // start TCP server

    return 0; // terminate program successfully
}