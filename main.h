//
// Created by Kevin on 10-4-2018.
//

#ifndef CBACKEND_MAIN_H
#define CBACKEND_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#if defined(_WIN32)
#define PORT 8000
#include <winsock2.h>
#elif defined(__linux__)
#define PORT 9000
#include <sys/socket.h>
#endif
int main(int argc, const char* argv[]){
    printf(PORT + "");
    //int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("Hello World");
}

#endif //CBACKEND_MAIN_H
