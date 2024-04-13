#include "HandlerLocal.h"
#include <iostream>
int main(int argc, char* argv[]) {
    std::cout << "Hello world\n";
    HandlerLocal local;
    local.handleMessage("Yoshi is King");
    return 1;
}
