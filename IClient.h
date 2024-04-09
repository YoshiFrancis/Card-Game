#ifndef ICLIENT_H
#define ICLIENT_H

#include <string_view>

class IPlayer;

class IClient {

    virtual bool sendMessage(std::string_view message) = 0;
    virtual std::string_view receiveMessage() = 0;
    virtual IPlayer* getPlayer() = 0;
    virtual void endConnection() = 0;

};

#endif 