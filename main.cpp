//
// Created by Kevin on 10-4-2018.
//

#include "main.h"

int main(int argc, const char* argv[]) {
    char str[100];
    int listen_fd, comm_fd;

    struct sockaddr_in servaddr;

    listen_fd = (int) socket(AF_INET, SOCK_STREAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(80);

    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    listen(listen_fd, 10);

    comm_fd = accept(listen_fd, (struct sockaddr *) NULL, NULL);
    while (1) {

        read(comm_fd, str, 100);

        printf("Echoing back - %s\n", str);

        write(comm_fd, str, strlen(str) + 1);

        str[100] = {0};

        sleep(1);
    }
    exit(0);
}

