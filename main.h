//
// Created by Kevin on 10-4-2018.
//

#ifndef CBACKEND_MAIN_H
#define CBACKEND_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

int main(int argc, const char* argv[]){
    printf("Hello World!");
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    exit(0);
}

#endif //CBACKEND_MAIN_H
