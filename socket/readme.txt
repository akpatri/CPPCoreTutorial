int socket(int domain, int type, int protocol)
int setsockopt(int sockfd, int level, int optname, const void* optval, socklen_t option)

address represenation with sockaddr_in
int bind(omt spclfd. const struct sockaddr*addr, socklen_t addreln)
int listen(int sockfd, int backlog)
int accept(int sockfd, struct sockaddr* addr, socklen_t *addrlen)
int connect(int sockfd, const struct sockadddr* addr. socklen_t addrlen )
int inet_pton(int af, const char*src, void* dst)
ssize_t_read(int fd, void *buf, size_t count)
ssize_t write(int fd, const void * buf, size_t cont)
int close(int fd)

/*
serverT.cpp

create tcp/udp socket( sockt())
bind to ip:port(bind())
for tcp:listen for client(listen())
accept connceitons(accept())
read/write(recv()/send(), read()/write())
shutdown/close(shutdonw()/clsoe())
*/


/*
create TCP/UDP socket(socket())
Setup server address(IP:port)
for TCP:connect(connect())
for UDP: send/receive (sendto()/recvfrom())
read/write(recv()/send())
Shutdown/clse(shoutdown()/clsoe())
*/




==================================
```txt id="compact-socket-readme"
SOCKET PROGRAMMING README
=========================


SOCKET BASICS
=============

Socket = communication endpoint between programs over network

IP Address = machine address
Port       = application/service number
Socket FD  = integer id returned by socket()

Example:
127.0.0.1:8080
127.0.0.1 -> localhost
8080      -> port


TCP vs UDP
==========

TCP:
- connection oriented
- reliable
- ordered
- uses connect/listen/accept

Flow:
client connect -> communicate -> close

UDP:
- connectionless
- fast
- unreliable
- packet/datagram based
- no connect/listen/accept

Flow:
send packet directly


IMPORTANT TYPES
===============

int       -> stores fd/status/port
ssize_t   -> stores bytes count or -1
socklen_t -> stores structure size


socket()
========

Prototype:
int socket(int domain, int type, int protocol);

Purpose:
create socket

Parameters:
domain   -> AF_INET=IPv4 AF_INET6=IPv6
type     -> SOCK_STREAM=TCP SOCK_DGRAM=UDP
protocol -> usually 0

Returns:
success -> socket fd
failure -> -1

Example:
int fd = socket(AF_INET, SOCK_STREAM, 0);
create IPv4 TCP socket


sockaddr_in
===========

Purpose:
stores IP + PORT

Fields:
sin_family -> IPv4/IPv6
sin_port   -> port
sin_addr   -> IP address

Example:
sockaddr_in addr{};

addr.sin_family = AF_INET;
addr.sin_port = htons(8080);

inet_pton(
    AF_INET,
    "127.0.0.1",
    &addr.sin_addr
);


htons()
========

Prototype:
htons(port)

Purpose:
convert port host format -> network format

Example:
addr.sin_port = htons(8080);


inet_pton()
===========

Prototype:
int inet_pton(int af, const char *src, void *dst);

Purpose:
convert IP string -> binary

Parameters:
af  -> AF_INET / AF_INET6
src -> IP string
dst -> destination variable

Returns:
1  -> success
0  -> invalid IP
-1 -> error

Example:
inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);


bind()
======

Prototype:
int bind(int sockfd, const sockaddr *addr, socklen_t addrlen);

Purpose:
attach socket to IP:PORT

Used By:
mainly server

Parameters:
sockfd  -> socket fd
addr    -> IP + PORT structure
addrlen -> structure size

Returns:
0  -> success
-1 -> failure


listen()
========

Prototype:
int listen(int sockfd, int backlog);

Purpose:
put TCP socket into listening mode

TCP only:
YES

UDP:
NO

Parameters:
sockfd  -> server socket
backlog -> waiting queue size

Returns:
0  -> success
-1 -> failure


accept()
=========

Prototype:
int accept(int sockfd, sockaddr *addr, socklen_t *addrlen);

Purpose:
accept client connection

IMPORTANT:
accept() returns NEW client socket

Server socket:
keeps listening

New socket:
used for communication

Parameters:
sockfd  -> listening socket
addr    -> stores client info
addrlen -> structure size

Returns:
client socket fd
-1 on failure


connect()
==========

Prototype:
int connect(int sockfd, const sockaddr *addr, socklen_t addrlen);

Purpose:
connect client to server

TCP only:
YES

Parameters:
sockfd  -> client socket
addr    -> server address
addrlen -> structure size

Returns:
0  -> success
-1 -> failure


send()
======

Prototype:
ssize_t send(int sockfd, const void *data, size_t size, int flags);

Purpose:
send data

Parameters:
sockfd -> socket
data   -> data buffer
size   -> bytes to send
flags  -> usually 0

Returns:
>0 -> bytes sent
-1 -> error


recv()
======

Prototype:
ssize_t recv(int sockfd, void *buffer, size_t size, int flags);

Purpose:
receive data

Parameters:
sockfd -> socket
buffer -> receive buffer
size   -> max bytes
flags  -> usually 0

Returns:
>0 -> bytes received
0  -> disconnected
-1 -> error


sendto()
========

Prototype:
ssize_t sendto(
    int sockfd,
    const void *data,
    size_t size,
    int flags,
    const sockaddr *addr,
    socklen_t addrlen
);

Purpose:
send UDP packet

Why address every time?
UDP has no connect()

Returns:
>0 -> bytes sent
-1 -> error


recvfrom()
==========

Prototype:
ssize_t recvfrom(
    int sockfd,
    void *buffer,
    size_t size,
    int flags,
    sockaddr *addr,
    socklen_t *addrlen
);

Purpose:
receive UDP packet + sender address

Returns:
>0 -> bytes received
-1 -> error


read()
======

Prototype:
ssize_t read(int fd, void *buf, size_t count);

Purpose:
read bytes from socket/file

Returns:
>0 -> bytes read
0  -> EOF/disconnect
-1 -> error


write()
=======

Prototype:
ssize_t write(int fd, const void *buf, size_t count);

Purpose:
write bytes to socket/file

Returns:
>0 -> bytes written
-1 -> error


shutdown()
==========

Prototype:
int shutdown(int sockfd, int how);

Purpose:
disable communication

Modes:
SHUT_RD   -> stop reading
SHUT_WR   -> stop writing
SHUT_RDWR -> stop both

Windows:
SD_RECEIVE
SD_SEND
SD_BOTH

Returns:
0  -> success
-1 -> error


close()
=======

Prototype:
int close(int fd);

Purpose:
release socket resource

Returns:
0  -> success
-1 -> error


setsockopt()
=============

Prototype:
int setsockopt(
    int sockfd,
    int level,
    int optname,
    const void *optval,
    socklen_t optlen
);

Purpose:
configure socket options

Common:
SO_REUSEADDR -> reuse port quickly


TCP SERVER FLOW
===============

socket()
    ↓
bind()
    ↓
listen()
    ↓
accept()
    ↓
recv()/read()
    ↓
send()/write()
    ↓
shutdown()
    ↓
close()


TCP CLIENT FLOW
===============

socket()
    ↓
connect()
    ↓
send()/write()
    ↓
recv()/read()
    ↓
shutdown()
    ↓
close()


UDP SERVER FLOW
===============

socket()
    ↓
bind()
    ↓
recvfrom()
    ↓
sendto()
    ↓
close()


UDP CLIENT FLOW
===============

socket()
    ↓
sendto()
    ↓
recvfrom()
    ↓
close()


TCP VISUAL
==========

CLIENT                         SERVER
------                         ------

socket()                    socket()
                             bind()
                             listen()

connect()  ------------->

                             accept()

send()     ------------->   recv()

recv()     <-------------   send()

close()                    close()


UDP VISUAL
==========

CLIENT                         SERVER
------                         ------

socket()                    socket()
                             bind()

sendto()   ------------->   recvfrom()

recvfrom() <-------------   sendto()

close()                    close()


FINAL MEMORY
=============

TCP:
socket -> bind -> listen -> accept -> recv/send -> close

UDP:
socket -> bind -> recvfrom/sendto -> close

TCP client:
socket -> connect -> send/recv -> close

UDP client:
socket -> sendto/recvfrom -> close
```
