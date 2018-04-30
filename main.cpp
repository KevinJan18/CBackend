//
// Created by Kevin on 10-4-2018.
//

#include "main.h"


int main(int argc, const char* argv[]) {
    if(argc != 2){
        printf("Not enough arguments, please pass an IP and Port, example: ./server 127.0.0.1 80\n");
        exit(1);
    }
    char* ip_addr = (char *) argv[0];//(char *) "127.0.0.1";
    int port = atoi(argv[1]);
    server = Server(port, ip_addr);
    server.startup();

    while (true){
        server.connect();

        char* data = server.getData();

        if(data == '\0') printf("Dat nullterminator tho\n");

        server.sendData(data);

        server.disconnect();
    }
    return 0;
}

