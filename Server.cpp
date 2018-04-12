//
// Created by Kevin on 10-4-2018.
//

#include "Server.h"


Server::Server(int port, char *ip_addr) {
    _port = port;
    //Saferead the IP
    _ip_addr = (char *) malloc(sizeof(char) * 15);
    cpString(ip_addr, _ip_addr);
}

void Server::startup() {

    _listen_fd = (int) socket(AF_INET, SOCK_STREAM, 0);

    _serveraddr.sin_family = AF_INET;
    _serveraddr.sin_addr.s_addr = htons(INADDR_ANY);
    _serveraddr.sin_port = htons(59);

    bind((SOCKET) _listen_fd, (struct sockaddr *) &_serveraddr, sizeof(_serveraddr));

    listen((SOCKET) _listen_fd, 10);

    _comm_fd = (int) accept((SOCKET) _listen_fd, (struct sockaddr *) NULL, NULL);
}

void Server::getData() {
    zeroTarget(_data);
    printf("Zeroed Data\n");
    printf("Listening\n");
    while(*_data == 0) {
        read(_comm_fd, _data, 100);
    }
    printf("Got Data\n");
    printf("Echoing back - %s\n", _data);
    write(_comm_fd, _data, (unsigned int) (strlen(_data)));
    printf("Wrote Data\n");

}

char *Server::toString() {
    char *string = (char *) malloc(sizeof(_ip_addr));
    cpString(_ip_addr, string);
    return string;
}

//Copies a byte array from one place to another, used for strings
void Server::cpString(char *source, char *dest) {
    zeroTarget(dest);
    int size = sizeof(source) + 1;
    for (int i = 0; i <= size; i++) {
        *dest = *source;
        dest++;
        source++;
    }
    source -= size;
    dest -= size;
}

//Zeroes the targeted byte array.
void Server::zeroTarget(char *target) {
    int size = sizeof(target);
    for (int i = 0; i <= size; i++) {
        *target = 0;
        target++;
    }
    target -= size;
}