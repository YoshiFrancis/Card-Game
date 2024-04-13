#ifndef IHANDLER_H
#define IHANDLER_H

#include <string_view>

class IClient;

class IHandler {

public:

    virtual bool sendMessage(const IClient& client, std::string_view message) = 0;
    virtual void handleMessage(std::string_view message) = 0;
    virtual void receiveMessage(std::string_view message) = 0;
    virtual void shutdown() = 0;
    virtual void endConnection(const IClient& client) = 0;

};


#endif
