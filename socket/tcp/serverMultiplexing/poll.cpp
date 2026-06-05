/*
TCP SERVER USING poll()

Overview:
----------------------------------------------------------------
This program implements a multi-client TCP server using the
poll() I/O multiplexing mechanism.

poll() allows a single thread to monitor multiple sockets
simultaneously and detect when they become ready for I/O
operations such as reading incoming data or accepting new
connections.

Unlike select(), poll() does not require fd_set structures
and is not limited by FD_SETSIZE. Instead, it uses an array
of pollfd structures, making it more flexible for handling
larger numbers of connections.

The server follows an event-driven architecture where one
thread waits for socket events and processes them as they
occur.

Core Responsibilities:
----------------------------------------------------------------
1. Create TCP server socket.
2. Bind socket to an IP address and port.
3. Put socket into listening mode.
4. Create and maintain pollfd array/vector.
5. Register listening socket with poll().
6. Wait for socket events using poll().
7. Accept new client connections.
8. Add connected clients to poll monitoring list.
9. Receive messages from connected clients.
10. Send responses back to clients.
11. Detect client disconnects.
12. Remove disconnected clients from monitoring.
13. Release socket and networking resources.

Functions:
----------------------------------------------------------------
initializeWinsock()
    Initializes Winsock networking library on Windows.
    Required before any socket operations on Windows.
    No-op on Linux.
    return:
        true  -> success
        false -> failure

createSocket()
    Creates IPv4 TCP socket.

    Internally calls:
        socket(AF_INET, SOCK_STREAM, 0)

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

    Internally calls:
        bind()

    return:
        true  -> success
        false -> failure

startListening(int serverFd, int backlog)
    Places socket into passive listening mode.

    Internally calls:
        listen()

    return:
        true  -> success
        false -> failure

acceptClient(int serverFd, vector<pollfd>& pollFds)
    Accepts a pending client connection.

    Creates a new communication socket for the client.

    Adds client socket to poll monitoring list.

    Internally calls:
        accept()

handleClientMessage(int clientFd, vector<pollfd>& pollFds)
    Processes activity detected on a client socket.

    Handles:
        - recv()
        - send()
        - disconnect detection
        - removal from poll list
        - socket cleanup

readMessage(int clientFd)
    Receives bytes from connected client.

    Internally calls:
        recv()

    return:
        string -> received message
        ""     -> error/disconnect

writeMessage(int clientFd, const string& msg)
    Sends data to connected client.

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
    Releases server resources.

    Performs:
        close()/closesocket()
        WSACleanup() (Windows)

runPollLoop(int serverFd)
    Main event-processing loop.

    Creates and maintains:
        vector<pollfd>

    Uses:
        poll()

    Handles:
        - new connections
        - incoming client messages
        - client disconnects
        - socket cleanup

tcpServer()
    Coordinates complete server startup and shutdown.

    Handles:
        socket creation
        bind
        listen
        poll loop
        cleanup

main()
    Program entry point.

    Starts the TCP server.

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
create pollfd list
        ↓
add serverFd
        ↓
while(true)
        ↓
poll()
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
add fd   message.empty() ?
   │         │
   │    ┌────┴────┐
   │    │         │
   │   NO        YES
   │    │         │
   │  send()   remove fd
   │              │
   │         shutdown()
   │              │
   │            close()
   │
   └──────────────┘

Key Data Structures:
----------------------------------------------------------------
pollfd
    Structure used by poll() to monitor sockets.

    Contains:
        fd       -> socket descriptor
        events   -> events to monitor
        revents  -> events reported by kernel

vector<pollfd>
    Dynamic container storing all monitored sockets.

    Includes:
        - listening socket
        - all connected client sockets

Key System Calls Used:
----------------------------------------------------------------
socket()      -> create TCP socket
bind()        -> attach socket to address
listen()      -> enable connection queue
accept()      -> accept client connection
recv()        -> receive client data
send()        -> send response
shutdown()    -> stop communication
close()       -> release socket descriptor

poll()        -> wait for socket activity

Advantages of poll():
----------------------------------------------------------------
- Simpler than epoll()
- More scalable than select()
- No FD_SETSIZE limitation
- Supports large numbers of descriptors
- Portable across Unix/Linux systems
- Dynamic descriptor management

Limitations of poll():
----------------------------------------------------------------
- Scans entire pollfd array on every call
- Performance decreases as connection count grows
- Less scalable than epoll()
- Not ideal for very high concurrency workloads

Comparison:
----------------------------------------------------------------
select()
    - Simplest API
    - FD_SETSIZE limitation
    - Scans all descriptors

poll()
    - No FD_SETSIZE limitation
    - Dynamic descriptor list
    - Better scalability than select()

epoll()
    - Linux-specific
    - Reports only active sockets
    - Best scalability
    - Preferred for high-performance servers

This implementation demonstrates an intermediate
event-driven networking model and serves as a bridge
between select() and epoll()-based server architectures.
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
#include <poll.h>       // poll(), pollfd, POLLIN

#define CLOSE_SOCKET close // Linux socket close function

#endif

#include <vector> // dynamic array for pollfd storage

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
ACCEPT CLIENT CONNECTION
--------------------------------------------------------------
Accepts new client and adds it to poll list.
===========================================================*/
void acceptClient(
    int serverFd,            // listening server socket
    vector<pollfd> &pollFds) // list of monitored sockets
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

    pollfd clientPollFd{}; // poll structure for new client

    clientPollFd.fd =
        clientFd; // store client socket descriptor

    clientPollFd.events =
        POLLIN; // monitor incoming data events

    pollFds.push_back(
        clientPollFd); // add client to poll monitoring list

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
    int clientFd,            // connected client socket
    vector<pollfd> &pollFds) // list of monitored sockets
{
    string message =
        readMessage(
            clientFd); // receive message from client

    if (message.empty()) // client disconnected or recv() failed
    {
        for (
            auto it = pollFds.begin(); // start of poll list
            it != pollFds.end();       // search entire poll list
            ++it)                      // move to next entry
        {
            if (it->fd == clientFd) // found disconnected client
            {
                pollFds.erase(
                    it); // remove client from poll monitoring

                break; // stop searching
            }
        }

        shutdownConnection(
            clientFd); // close client connection

        cout
            << "[INFO] connection closed"
            << endl; // notify client disconnection

        return; // stop processing
    }

    cout
        << "client: "
        << message
        << endl; // display received message

    writeMessage(
        clientFd,
        "hello from server"); // send response to client
}

/*===========================================================
POLL EVENT LOOP
--------------------------------------------------------------
Waits for events and processes sockets.
===========================================================*/
void runPollLoop(
    int serverFd) // listening server socket
{
    vector<pollfd> pollFds; // stores all monitored sockets

    pollfd serverPollFd{}; // poll structure for server socket

    serverPollFd.fd =
        serverFd; // store listening socket descriptor

    serverPollFd.events =
        POLLIN; // monitor incoming connection events

    pollFds.push_back(
        serverPollFd); // add server socket to poll list

    while (true) // run server continuously
    {
        int ready =
            poll(
                pollFds.data(), // array of monitored sockets
                pollFds.size(), // number of monitored sockets
                -1);            // wait indefinitely

        if (ready == -1) // poll() failed
        {
            perror("poll"); // print system error

            break; // exit event loop
        }

        int count =
            static_cast<int>(
                pollFds.size()); // current number of sockets

        for (
            int i = 0; // start from first socket
            i < count; // process all monitored sockets
            ++i)       // move to next socket
        {
            if (
                !(pollFds[i].revents & POLLIN)) // socket not ready for reading
            {
                continue; // skip this socket
            }

            int fd =
                pollFds[i].fd; // retrieve socket descriptor

            if (fd == serverFd) // new client connection event
            {
                acceptClient(
                    serverFd,
                    pollFds); // accept and register client
            }
            else // existing client sent data
            {
                handleClientMessage(
                    fd,
                    pollFds); // process client message
            }
        }
    }
}

/*===========================================================
START POLL SERVER
--------------------------------------------------------------
Creates and runs poll based TCP server.
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

    cout
        << "\nserver running...\n"
        << endl; // notify server startup

    runPollLoop(
        serverFd); // start poll event loop

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
    tcpServer(); // start poll-based TCP server

    return 0; // terminate program successfully
}