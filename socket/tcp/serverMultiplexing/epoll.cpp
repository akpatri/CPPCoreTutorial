/*
TCP SERVER USING epoll()

Overview:
----------------------------------------------------------------
This program implements a multi-client TCP server using Linux's
epoll I/O event notification mechanism.

Unlike select(), epoll does not repeatedly scan all file
descriptors. The kernel directly reports only sockets that
have become ready, making epoll highly scalable for handling
thousands of concurrent client connections.

The server follows an event-driven architecture where a single
thread waits for socket events and reacts to them as they occur.

Core Responsibilities:
----------------------------------------------------------------
1. Create TCP server socket.
2. Bind socket to an IP address and port.
3. Put socket into listening mode.
4. Create an epoll instance.
5. Register the listening socket with epoll.
6. Wait for socket events using epoll_wait().
7. Accept new client connections.
8. Register connected clients with epoll.
9. Receive messages from connected clients.
10. Send responses back to clients.
11. Detect client disconnects.
12. Remove disconnected clients from epoll.
13. Release all socket and networking resources.

Functions:
----------------------------------------------------------------
initializeWinsock()
    Initializes Winsock library on Windows.
    No-op on Linux.
    return:
        true  -> success
        false -> failure

createSocket()
    Creates IPv4 TCP socket.
    return:
        int -> socket descriptor
        -1  -> failure

createServerAddress(int port)
    Creates and configures server address structure.
    Sets:
        - IPv4 address family
        - listening port
        - INADDR_ANY
    return:
        sockaddr_in

bindSocket(int serverFd, sockaddr_in& addr)
    Attaches socket to IP:PORT.
    return:
        true  -> success
        false -> failure

startListening(int serverFd, int backlog)
    Places socket into passive listening mode.
    return:
        true  -> success
        false -> failure

createEpollInstance()
    Creates epoll object used for event monitoring.
    Internally calls:
        epoll_create1()
    return:
        int -> epoll descriptor
        -1  -> failure

addToEpoll(int epollFd, int fd)
    Registers a socket with epoll.
    Interested in:
        EPOLLIN (readable events)
    Internally calls:
        epoll_ctl(EPOLL_CTL_ADD)
    return:
        true  -> success
        false -> failure

acceptClient(int serverFd, int epollFd)
    Accepts a pending client connection.
    Creates a new client socket.
    Registers the client socket with epoll.
    Handles:
        - accept()
        - epoll_ctl(ADD)

handleClientMessage(int epollFd, int clientFd)
    Processes activity on a client socket.
    Handles:
        - recv()
        - send()
        - disconnect detection
        - epoll_ctl(DEL)
        - socket cleanup

readMessage(int clientFd)
    Receives bytes from connected client.
    Internally calls:
        recv()
    return:
        string -> received message
        ""     -> error/disconnect

writeMessage(int clientFd, const string& msg)
    Sends bytes to connected client.
    Internally calls:
        send()
    return:
        true  -> success
        false -> failure

shutdownConnection(int fd)
    Gracefully terminates connection.
    Performs:
        shutdown()
        close()/closesocket()

closeServer(int serverFd)
    Releases server socket resources.
    Performs:
        close()/closesocket()
        WSACleanup() (Windows)

runEpollLoop(int serverFd, int epollFd)
    Main event-processing loop.
    Waits for socket activity using:
        epoll_wait()

    Handles:
        - new connections
        - incoming client messages
        - client disconnects
        - socket cleanup

tcpServer()
    Coordinates complete server setup:
        socket
        bind
        listen
        epoll creation
        event loop
        cleanup

main()
    Program entry point.
    Starts TCP server.

Execution Flow:
----------------------------------------------------------------
initializeWinsock()
        ↓
createSocket()
        ↓
createServerAddress()
        ↓
bind()
        ↓
listen()
        ↓
epoll_create1()
        ↓
epoll_ctl(ADD serverFd)
        ↓
while(true)
        ↓
epoll_wait()
        ↓
 ┌─────────────────────────────┐
 │ Ready Event Received        │
 └─────────────────────────────┘
        ↓
   fd == serverFd ?
        │
   ┌────┴────┐
   │         │
  YES       NO
   │         │
accept()   recv()
   │         │
   │    message.empty() ?
   │         │
   │    ┌────┴────┐
   │    │         │
   │   NO        YES
   │    │         │
   │  send()   client disconnected
   │              │
   │        epoll_ctl(DEL)
   │              │
   │         shutdown()
   │              │
   │           close()
   │
epoll_ctl(ADD clientFd)
   │
   └──────────────┘


Key System Calls Used:
----------------------------------------------------------------
socket()          -> create TCP socket
bind()            -> attach socket to address
listen()          -> enable connection queue
accept()          -> accept client connection
recv()            -> receive client data
send()            -> send response
shutdown()        -> disable socket communication
close()           -> release socket descriptor

epoll_create1()   -> create epoll instance
epoll_ctl()       -> register/remove monitored sockets
epoll_wait()      -> wait for socket events


Advantages of epoll:
----------------------------------------------------------------
- Designed for large-scale concurrent network servers
- Efficiently handles thousands of client connections
- Kernel reports only sockets that are ready
- Avoids repeatedly scanning all descriptors
- Lower CPU overhead than select() and poll()
- No FD_SETSIZE limitation
- Supports both level-triggered and edge-triggered modes
- Widely used in high-performance Linux servers
  such as web servers, proxies, and chat servers
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
#include <sys/epoll.h>  // epoll_create1(), epoll_ctl(), epoll_wait()

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
CREATE EPOLL INSTANCE
--------------------------------------------------------------
Creates epoll instance used for event monitoring.
===========================================================*/
int createEpollInstance()
{
    int epollFd =
        epoll_create1(
            0); // create epoll instance with default flags

    if (epollFd == -1) // epoll creation failed
    {
        perror("epoll_create1"); // print operating system error

        return -1; // indicate failure
    }

    cout
        << "[OK] epoll instance created"
        << endl; // epoll successfully created

    return epollFd; // return valid epoll descriptor
}

/*===========================================================
ADD FILE DESCRIPTOR TO EPOLL
--------------------------------------------------------------
Registers socket so epoll can monitor it.
===========================================================*/
bool addToEpoll(
    int epollFd, // epoll instance descriptor
    int fd)      // socket to monitor
{
    epoll_event event{}; // epoll event structure

    event.events =
        EPOLLIN; // notify when socket becomes readable

    event.data.fd =
        fd; // store socket descriptor inside event

    if (
        epoll_ctl(
            epollFd,       // epoll instance
            EPOLL_CTL_ADD, // add new descriptor
            fd,            // descriptor being registered
            &event) == -1) // event configuration
    {
        perror("epoll_ctl ADD"); // print operating system error

        return false; // registration failed
    }

    return true; // registration successful
}

/*===========================================================
ACCEPT CLIENT CONNECTION
--------------------------------------------------------------
Accepts new client and adds it to epoll.
===========================================================*/
void acceptClient(
    int serverFd, // listening server socket
    int epollFd)  // epoll instance descriptor
{
    sockaddr_in clientAddr{}; // stores client address information

    socklen_t clientLen =
        sizeof(clientAddr); // size of client address structure

    int clientFd =
        accept(
            serverFd,                // listening server socket
            (sockaddr *)&clientAddr, // receive client address
            &clientLen);             // receive address size

    if (clientFd == -1) // accept() failed
    {
        perror("accept"); // print system error

        return; // stop processing
    }

    if (
        !addToEpoll(
            epollFd,   // epoll instance
            clientFd)) // newly connected client socket
    {
        shutdownConnection(
            clientFd); // cleanup client resources

        return; // stop processing
    }

    cout
        << "[OK] client connected"
        << endl; // notify successful connection
}
/*===========================================================
HANDLE CLIENT MESSAGE
--------------------------------------------------------------
Reads client message and sends response.
===========================================================*/
void handleClientMessage(
    int epollFd,  // epoll instance
    int clientFd) // connected client socket
{
    string message =
        readMessage(
            clientFd); // receive message from client

    if (message.empty()) // client disconnected or recv failed
    {
        epoll_ctl(
            epollFd,       // epoll instance
            EPOLL_CTL_DEL, // remove descriptor
            clientFd,      // client socket
            nullptr);      // no event structure needed

        shutdownConnection(
            clientFd); // release client resources

        cout
            << "[INFO] connection closed"
            << endl; // notify disconnect

        return; // stop processing client
    }

    cout
        << "client: "
        << message
        << endl; // display received message

    writeMessage(
        clientFd,
        "hello from server"); // send reply
}

/*===========================================================
EPOLL EVENT LOOP
--------------------------------------------------------------
Waits for events and processes sockets.
===========================================================*/
void runEpollLoop(
    int serverFd, // listening socket
    int epollFd)  // epoll instance
{
    epoll_event events[64]; // receives triggered events

    while (true) // run server forever
    {
        int ready =
            epoll_wait(
                epollFd, // epoll instance
                events,  // output event array
                64,      // maximum events returned
                -1);     // wait indefinitely

        if (ready == -1) // epoll_wait failed
        {
            perror("epoll_wait"); // print operating system error

            break; // exit event loop
        }

        for (
            int i = 0; // first ready event
            i < ready; // process all ready events
            ++i)       // next event
        {
            int fd =
                events[i].data.fd; // retrieve socket descriptor

            if (fd == serverFd) // new connection request
            {
                acceptClient(
                    serverFd,
                    epollFd); // accept and register client
            }
            else // existing client activity
            {
                handleClientMessage(
                    epollFd,
                    fd); // process client data
            }
        }
    }
}

/*===========================================================
START EPOLL SERVER
--------------------------------------------------------------
Creates and runs epoll based TCP server.
===========================================================*/
void tcpServer()
{
    if (!initializeWinsock()) // initialize networking subsystem
    {
        return; // stop if initialization failed
    }

    int serverFd =
        createSocket(); // create TCP server socket

    if (serverFd == -1) // socket creation failed
    {
        return; // cannot continue without socket
    }

    sockaddr_in serverAddr =
        createServerAddress(
            8080); // configure server address and port

    if (
        !bindSocket(
            serverFd,
            serverAddr)) // bind socket to IP:PORT
    {
        closeServer(
            serverFd); // release server resources

        return; // stop on bind failure
    }

    if (
        !startListening(
            serverFd)) // place socket into listening mode
    {
        closeServer(
            serverFd); // release server resources

        return; // stop on listen failure
    }

    int epollFd =
        createEpollInstance(); // create epoll monitoring instance

    if (epollFd == -1) // epoll creation failed
    {
        closeServer(
            serverFd); // release server resources

        return; // stop on epoll creation failure
    }

    if (
        !addToEpoll(
            epollFd,   // epoll instance
            serverFd)) // listening server socket
    {
        CLOSE_SOCKET(
            epollFd); // release epoll descriptor

        closeServer(
            serverFd); // release server resources

        return; // stop if registration failed
    }

    cout
        << "\nserver running...\n"
        << endl; // notify server startup

    runEpollLoop(
        serverFd,
        epollFd); // start epoll event loop

    CLOSE_SOCKET(
        epollFd); // release epoll descriptor

    closeServer(
        serverFd); // cleanup server resources
}

/*===========================================================
MAIN
--------------------------------------------------------------
Program entry point.
===========================================================*/
int main()
{
    tcpServer(); // start epoll-based TCP server

    return 0; // terminate program successfully
}