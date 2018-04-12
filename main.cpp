//
// Created by Kevin on 10-4-2018.
//

#include "main.h"


int main(int argc, const char* argv[]) {
    char* ip_addr = (char *) "127.0.0.1";
    server = Server(80, (char *) "127.0.0.2");
    server.startup();
    while(true) {
        server.getData();

        if(server.data == "kill"){
            break;
        }

        sleep(100);
    }
    return 0;
}

