#ifndef IHANDLER_H
#define IHANDLER_H

#include <string_view>

class IClient;

class IHandler {

public:
    IServer() = default;
    virtual bool sendMessage(const IClient& client, std::string_view message) = 0;
    virtual void handleMessage(const IClient& sender, std::string_view message) = 0;
    virtual std::string_view receiveMessage() = 0;
    virtual void shutdown() = 0;
    virtual void endConnection(const IClient& client) = 0;
    

};

#endif
