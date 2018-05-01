
#ifndef CBACKEND_MAIN_H
#define CBACKEND_MAIN_H

#include <stdio.h>
#include "../lib/Server/Server.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#if defined(_WIN32)
#define PORT 666
#include <winsock2.h>
#elif defined(__linux__)
#define PORT 666
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#endif

Server server;

#endif
