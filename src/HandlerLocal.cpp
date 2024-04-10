#include "HandlerLocal.h"

bool sendMessage(const IClient& client, std::string_view message) override {
    client.receiveMessage(message);
}

void handleMessage(std::string_view message) override {
    
    // do stuff with message
}

void receiveMessage(std::string_view message) override {

    handleMessage(message);
}

void endConnection(const IClient& client) override {
    
}



