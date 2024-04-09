#ifndef ICOMMUNICATOR_H
#define ICOMMUNICATOR_H

#include <string_view>

class IServer;
class IClient;

class ICommunicator {

    virtual void setup() = 0;
    virtual void addClient(const IClient& client) = 0;
    virtual void removeClient(std::string_view username) = 0;
    virtual const IServer* getServer() = 0;
    virtual IClient* findClient(std::string_view username) = 0;
    virtual void sendMessage(const IClient& client, std::string_view message) = 0;
    

};

#endif