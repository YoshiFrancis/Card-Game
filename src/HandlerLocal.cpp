#include "HandlerLocal.h"
#include <iostream>

bool HandlerLocal::sendMessage(const IClient& client, std::string_view message) {
//  client.receiveMessage(message);
    return true;
}

void HandlerLocal::handleMessage(std::string_view message) {
    std::cout << message << "\n";
    // do stuff with message
}

void HandlerLocal::receiveMessage(std::string_view message) {
    handleMessage(message);
}

void HandlerLocal::endConnection(const IClient& client) {
    
}



