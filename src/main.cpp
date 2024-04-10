
#include "ServerLocal.h"
#include <iostream>
int main(int argc, char* argv[]) {
    std::cout << "Hello world\n";
    ServerLocal local;
    std::cout << local.receiveMessage() << "\n";
    return 1;
}