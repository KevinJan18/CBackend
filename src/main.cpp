//
// Created by Kevin on 10-4-2018.
//

#include "main.h"


int main(int argc, const char* argv[]) {
    char* ip_addr = (char *) "127.0.0.1";
    server = Server(666, ip_addr);
    server.startup();

    while (true){
        server.connect();

        server.getData();

        server.disconnect();
    }
    return 0;
}
