//
// Created by Kevin on 10-4-2018.
//

#ifndef CBACKEND_MAIN_H
#define CBACKEND_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char* argv[]){
    printf("Hello World!");
    while(1){
        printf("Hello World!");
        sleep(5);
    }
    exit(0);
}

#endif //CBACKEND_MAIN_H
