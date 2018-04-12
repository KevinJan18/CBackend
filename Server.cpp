//
// Created by Kevin on 10-4-2018.
//

#include "Server.h"


Server::Server(int port, char* ip_addr){
    _port = port;
    //Saferead the IP
    _ip_addr = (char *) malloc(sizeof(char) * 15);
    cpString(ip_addr, _ip_addr);
}

void Server::startup(){

    _listen_fd = (int) socket(AF_INET, SOCK_STREAM, 0);

    _servaddr.sin_family = AF_INET;
    _servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    _servaddr.sin_port = htons(80);

    bind((SOCKET) _listen_fd, (struct sockaddr *) &_servaddr, sizeof(_servaddr));

    listen((SOCKET) _listen_fd, 10);

    _comm_fd = (int) accept((SOCKET) _listen_fd, (struct sockaddr *) NULL, NULL);
}

void Server::getData(){
    while (1) {
        read(_comm_fd, _data, 100);

        printf("Echoing back - %s\n",_data);

        write(_comm_fd, _data, (unsigned int) (strlen(_data) + 1));
    }

}

char *Server::toString() {
    char* string = (char*) malloc(sizeof(_ip_addr));
    cpString(_ip_addr, string);
    zeroTarget(string);
    return string;
}

void Server::cpString(char* source, char* dest){
    char* desttemp = dest;
    char* sourcetemp = source;
    while(*sourcetemp){
        *dest = *sourcetemp;
        dest++;
        sourcetemp++;
    }
    source = sourcetemp;
    dest = desttemp;
}

void Server::zeroTarget(char* target){
    int size = sizeof(target);
    for(int i = 0; i <= size;i++){
        *target = 0;
        target++;
    }
    target -= size;
}