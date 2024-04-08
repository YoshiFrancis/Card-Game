#ifndef ISERVER_H
#define ISERVER_H

#include <string_view>

class IClient;

class IServer {

    virtual bool sendMessage(const IClient& client, std::string_view message) = 0;
    virtual std::string_view receiveMessage() = 0;
    

};

#endif