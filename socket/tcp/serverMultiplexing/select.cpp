/*
TCP SERVER USING select()

Functions:
----------------------------------------------------------------
createSocket()
    Creates IPv4 TCP socket.
    return:
        int -> socket fd
        -1  -> failure

bindSocket(int serverFd, sockaddr_in& addr)
    Binds socket to IP:PORT.
    params:
        serverFd -> listening socket
        addr     -> server address
    return:
        true  -> success
        false -> failure

startListening(int serverFd, int backlog)
    Puts socket into passive mode.
    return:
        true/false

runSelectLoop(int serverFd)
    Monitors multiple sockets using select().
    Handles:
        - new client connections
        - incoming messages
        - client disconnects

readMessage(int clientFd)
    Receives data from client.
    return:
        string message

writeMessage(int clientFd, const string& msg)
    Sends data to client.
    return:
        true/false

shutdownConnection(int fd)
    shutdown() + close()

Flow:
----------------------------------------------------------------
socket()
 ↓
bind()
 ↓
listen()
 ↓
FD_ZERO()
 ↓
FD_SET(serverFd)
 ↓
select()
 ├── new connection → accept()
 └── client data    → recv()
                       ↓
                     send()
                       ↓
                  close client
*/

#include <iostream>
#include <cstring>

#ifdef _WIN32

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define CLOSE_SOCKET closesocket

#else

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>

#define CLOSE_SOCKET close

#endif

using namespace std;

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

// Accepts a new client and registers it for future select() monitoring.
void acceptClient(
    int serverFd,      // listening socket that receives connection requests
    fd_set &masterSet, // master set containing every monitored socket
    int &maxFd)        // highest descriptor currently stored in masterSet
{
    sockaddr_in clientAddr{}; // receives the connected client's IP address and port

    socklen_t clientLen =
        sizeof(clientAddr); // size of clientAddr required by accept()

    int clientFd =
        accept(
            serverFd,                // listening socket waiting for new clients
            (sockaddr *)&clientAddr, // receives information about the connected client
            &clientLen);             // input: buffer size, output: actual size written

    // accept() creates a NEW communication socket:
    // serverFd continues listening
    // clientFd is used for recv() and send()

    if (clientFd == -1) // accept() failed to establish a connection
    {
        perror("accept"); // print operating system error message

        return; // no valid client socket was created
    }

    FD_SET(
        clientFd,
        &masterSet); // add clientFd so future select() calls monitor this client

    if (clientFd > maxFd) // select() only scans descriptors up to maxFd
    {
        maxFd = clientFd; // update scan range when a larger descriptor appears
    }

    cout
        << "[OK] client connected"
        << endl; // connection accepted successfully
}

void runServer(int serverFd)
{
    fd_set masterSet; // fd_set stores all sockets monitored by select()

    FD_ZERO(&masterSet); // remove all descriptors before adding sockets to the set

    FD_SET(
        serverFd,
        &masterSet); // add listening socket so select() can detect new connections

    int maxFd =
        serverFd; // highest descriptor currently in masterSet

    while (true) // server continuously waits for socket activity
    {
        fd_set readSet =
            masterSet; // select() modifies the supplied set, so keep masterSet unchanged

        int ready =
            select(
                maxFd + 1, // select() scans descriptors from 0 to maxFd
                &readSet,  // sockets checked for incoming data
                nullptr,   // not interested in write readiness
                nullptr,   // not interested in exceptional conditions
                nullptr);  // block until at least one socket becomes ready

        if (ready < 0) // select() failed
        {
            perror("select"); // print operating system error

            break; // terminate event loop
        }

        for (
            int fd = 0;  // start from descriptor 0
            fd <= maxFd; // check every descriptor being tracked
            ++fd)        // move to next descriptor
        {
            if (
                !FD_ISSET(
                    fd,
                    &readSet)) // select() did not report activity for this socket
            {
                continue; // skip inactive socket
            }

            if (fd == serverFd) // activity on listening socket indicates a connection request
            {
                acceptClient(
                    serverFd,  // listening socket accepting new clients
                    masterSet, // client socket will be added here
                    maxFd);    // update highest descriptor if necessary
            }
            else // activity on client socket indicates data or disconnect
            {
                handleClientMessage(
                    fd,         // connected client socket
                    masterSet); // may remove socket if client disconnects
            }
        }
    }
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

// Handles activity detected by select() on a client socket.
void handleClientMessage(
    int clientFd,      // connected client used for recv() and send()
    fd_set& masterSet) // master set used by select()
{
    string message =
        readMessage(clientFd); // read client data using recv()

    if (message.empty()) // empty string means recv() failed or client disconnected
    {
        FD_CLR(
            clientFd,
            &masterSet); // stop monitoring this socket because it is no longer usable

        shutdownConnection(
            clientFd); // shutdown communication and release socket resources

        cout
            << "[INFO] connection closed"
            << endl; // notify that the client connection ended

        return; // no further processing is possible for this client
    }

    cout
        << "client: "
        << message
        << endl; // display the message received from the client

    writeMessage(
        clientFd,
        "hello from server"); // send response back through the same TCP connection
}

// Creates, configures, and starts the TCP server.
void tcpServer()
{
    if (!initializeWinsock()) // initialize Winsock on Windows, no-op on Linux
    {
        return; // networking layer could not be initialized
    }

    int serverFd =
        createSocket(); // create IPv4 TCP socket

    if (serverFd == -1) // socket() failed
    {
        return; // cannot continue without a valid socket
    }

    sockaddr_in serverAddr =
        createServerAddress(
            8080); // configure server address and listening port

    if (
        !bindSocket(
            serverFd,
            serverAddr)) // attach socket to port 8080
    {
        closeServer(
            serverFd); // release socket before exiting

        return; // bind() failed, usually port already in use
    }

    if (
        !startListening(
            serverFd)) // put socket into listening mode
    {
        closeServer(
            serverFd); // release socket before exiting

            return; // listen() failed
    }

    cout
        << "\nserver running...\n"
        << endl; // server is ready to accept client connections

    runServer(
        serverFd); // enter select()-based event loop

    closeServer(
        serverFd); // cleanup socket and networking resources
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