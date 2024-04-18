#ifndef ICLIENT_H
#define ICLIENT_H

#include <string_view>

class IPlayer;

class IClient {

public: 

    virtual bool sendMessage(std::string_view message) const = 0;
    virtual bool receiveMessage(std::string_view message) const = 0;
    virtual IPlayer* getPlayer() const = 0;
    virtual void endConnection() = 0;

};

#endif 
