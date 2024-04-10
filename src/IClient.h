#ifndef ICLIENT_H
#define ICLIENT_H

#include <string_view>

class IPlayer;

class IClient {

    virtual bool sendMessage(const IHandler* handler, std::string_view message) = 0;
    virtual void receiveMessage(std::string_view message) = 0;
    virtual IPlayer* getPlayer() = 0;
    virtual void endConnection() = 0;

};

#endif 
