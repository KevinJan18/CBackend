//
// Created by Kevin on 10-4-2018.
//

#ifndef SIMPLE_EXAMPLE_SERVER_H
#define SIMPLE_EXAMPLE_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#if defined(_WIN32)
#define PORT 80
#include <winsock2.h>
#elif defined(__linux__)
#define PORT 80
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#endif

class Server {

public:
    Server(int port = 80, char* ip_addr = (char *) "localhost");
    void startup();
    void getData();
    void connect();
    void disconnect();
    char* toString();
    char data[100];
private:
    int _port;
    char* _ip_addr;
    int _listen_fd;
    int _comm_fd;

    struct sockaddr_in _serveraddr;
    void cpString(char* source, char* dest);
    void zeroTarget(char* target);
};


#endif
