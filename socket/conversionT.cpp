/*
================================================================
conversionT.cpp
----------------------------------------------------------------
NETWORK BYTE ORDER + IP ADDRESS CONVERSION DEMONSTRATION
================================================================

This file demonstrates commonly used networking conversion
functions used in TCP/IP socket programming.

WHY THESE CONVERSIONS ARE NEEDED?
----------------------------------------------------------------
Different computer architectures store bytes differently.

Example:
----------------------------------------------------------------
Little-endian system:
    Least Significant Byte stored first

Big-endian system:
    Most Significant Byte stored first

Internet protocols always use:
    BIG-ENDIAN format
    also called:
    "Network Byte Order"

Therefore conversion functions are required to ensure
correct communication between different systems.

================================================================
FUNCTIONS COVERED
================================================================

1. htons()
----------------------------------------------------------------
Host TO Network Short

Purpose:
    Converts 16-bit host byte order into
    network byte order.

Commonly used for:
    TCP/UDP port numbers

Example:
    8080 -> network format

================================================================

2. ntohs()
----------------------------------------------------------------
Network TO Host Short

Purpose:
    Converts 16-bit network byte order back into
    host byte order.

Commonly used for:
    reading received port numbers

================================================================

3. htonl()
----------------------------------------------------------------
Host TO Network Long

Purpose:
    Converts 32-bit host integer into
    network byte order.

Commonly used for:
    IPv4 integer values
    protocol fields
    packet headers

================================================================

4. ntohl()
----------------------------------------------------------------
Network TO Host Long

Purpose:
    Converts 32-bit network integer back into
    host byte order.

================================================================

5. inet_pton()
----------------------------------------------------------------
Presentation TO Network

Purpose:
    Converts readable IP string into
    binary network format.

Example:
    "192.168.1.10"
            ↓
    binary IPv4 address

Commonly used before:
    connect()
    bind()

================================================================

6. inet_ntop()
----------------------------------------------------------------
Network TO Presentation

Purpose:
    Converts binary IPv4 address into
    human-readable string.

Example:
    binary IPv4
            ↓
    "192.168.1.10"

Commonly used for:
    logging
    diagnostics
    printing client IP addresses

================================================================

THIS FILE DEMONSTRATES:
----------------------------------------------------------------
- Port conversion
- Integer conversion
- IPv4 string conversion
- Binary IP conversion
- Host ↔ Network byte ordering

================================================================
*/

#include <iostream> // provides cout, cerr, endl for console output

#include <string> // provides std::string class for string handling

#ifdef _WIN32

#include <winsock2.h> // provides socket(), htons(), ntohs(), htonl(), ntohl(), sockaddr_in

#include <ws2tcpip.h> // provides inet_pton(), inet_ntop(), INET_ADDRSTRLEN

#pragma comment(lib, "ws2_32.lib") // links Winsock networking library automatically

#else

#include <arpa/inet.h> // provides htons(), ntohs(), inet_pton(), inet_ntop() on Linux

#endif

#include <cstdint> // provides fixed-size integers like uint16_t and uint32_t
using namespace std;

/*===============================================================
INITIALIZE WINSOCK
===============================================================*/
bool initializeWinsock()
{
#ifdef _WIN32

    WSADATA wsa; // structure for Winsock startup info

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) // initialize Winsock library
    {
        cerr << "WSAStartup failed" << endl;

        return false; // initialization failure
    }

#endif

    return true; // initialization success
}

/*===============================================================
HOST -> NETWORK PORT CONVERSION
---------------------------------------------------------------
htons() = host to network short
Used for 16-bit port conversion.
===============================================================*/
uint16_t convertPortToNetworkOrder(uint16_t hostPort)
{
    return htons(hostPort); // convert CPU-native port -> big-endian network format
}

/*===============================================================
NETWORK -> HOST PORT CONVERSION
---------------------------------------------------------------
ntohs() = network to host short
===============================================================*/
uint16_t convertPortToHostOrder(uint16_t networkPort)
{
    return ntohs(networkPort); // convert big-endian network port -> CPU-native format
}

/*===============================================================
HOST -> NETWORK LONG CONVERSION
---------------------------------------------------------------
htonl() = host to network long
Used for 32-bit integer conversion.
===============================================================*/
uint32_t convertHostToNetworkLong(uint32_t hostValue)
{
    return htonl(hostValue); // convert 32-bit host integer -> network format
}

/*===============================================================
NETWORK -> HOST LONG CONVERSION
---------------------------------------------------------------
ntohl() = network to host long
===============================================================*/
uint32_t convertNetworkToHostLong(uint32_t networkValue)
{
    return ntohl(networkValue); // convert 32-bit network integer -> host format
}

/*===============================================================
STRING IP -> BINARY IPv4
---------------------------------------------------------------
inet_pton() = presentation to network
===============================================================*/
in_addr convertIpToBinary(const string &ipString)
{
    in_addr binaryIp{}; // stores binary IPv4 address

    int result = inet_pton(
        AF_INET,             // IPv4 conversion
        ipString.c_str(),   // readable IP string
        &binaryIp);         // output binary IPv4 address

    if (result <= 0) // conversion failure
    {
        cerr << "inet_pton failed" << endl;
    }

    return binaryIp; // return binary IPv4 address
}

/*===============================================================
BINARY IPv4 -> STRING IP
---------------------------------------------------------------
inet_ntop() = network to presentation
===============================================================*/
string convertIpToString(in_addr binaryIp)
{
    char ip[INET_ADDRSTRLEN]; // buffer for readable IPv4 string

    inet_ntop(
        AF_INET,      // IPv4 conversion
        &binaryIp,    // binary IPv4 address
        ip,           // output string buffer
        sizeof(ip));  // buffer size

    return string(ip); // convert char[] -> C++ string
}

/*===============================================================
PORT CONVERSION DEMO
===============================================================*/
void demonstratePortConversion()
{
    uint16_t hostPort = 8080; // CPU-native host port

    uint16_t networkPort = convertPortToNetworkOrder(hostPort); // host -> network conversion

    uint16_t restoredPort = convertPortToHostOrder(networkPort); // network -> host conversion

    cout << "\n========== PORT CONVERSION ==========" << endl;

    cout << "host port     : " << hostPort << endl;

    cout << "network port  : " << networkPort << endl;

    cout << "restored port : " << restoredPort << endl;

    cout << "=====================================\n" << endl;
}

/*===============================================================
LONG INTEGER CONVERSION DEMO
===============================================================*/
void demonstrateLongConversion()
{
    uint32_t hostValue = 123456789; // CPU-native integer

    uint32_t networkValue = convertHostToNetworkLong(hostValue); // host -> network conversion

    uint32_t restoredValue = convertNetworkToHostLong(networkValue); // network -> host conversion

    cout << "\n========== LONG CONVERSION ==========" << endl;

    cout << "host value     : " << hostValue << endl;

    cout << "network value  : " << networkValue << endl;

    cout << "restored value : " << restoredValue << endl;

    cout << "=====================================\n" << endl;
}

/*===============================================================
IP CONVERSION DEMO
===============================================================*/
void demonstrateIpConversion()
{
    string ipString = "192.168.1.10"; // readable IPv4 string

    in_addr binaryIp = convertIpToBinary(ipString); // string -> binary conversion

    string restoredIp = convertIpToString(binaryIp); // binary -> readable string conversion

    cout << "\n========== IP CONVERSION ==========" << endl;

    cout << "original ip : " << ipString << endl;

    cout << "binary ip   : " << binaryIp.s_addr << endl; // raw integer representation

    cout << "restored ip : " << restoredIp << endl;

    cout << "===================================\n" << endl;
}

/*===============================================================
MAIN
===============================================================*/
int main()
{
    if (!initializeWinsock()) // initialize Winsock on Windows
    {
        return -1; // stop program if initialization fails
    }

    demonstratePortConversion(); // demonstrate htons() + ntohs()

    demonstrateLongConversion(); // demonstrate htonl() + ntohl()

    demonstrateIpConversion(); // demonstrate inet_pton() + inet_ntop()

#ifdef _WIN32

    WSACleanup(); // cleanup Winsock resources

#endif

    return 0; // successful program termination
}