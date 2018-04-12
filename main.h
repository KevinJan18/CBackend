
#ifndef CBACKEND_MAIN_H
#define CBACKEND_MAIN_H

#include <stdio.h>
#include "Server.h"
#include <stdlib.h>
#include <unistd.h>
#if defined(_WIN32)
#define PORT 80
#include <winsock2.h>
#elif defined(__linux__)
#define PORT 80
#include <sys/types.h>
#include <sys/socket.h>
#endif

Server server;

#endif
