#ifndef ICONNECTION_H
#define ICONNECTION_H

#include <string_view>

class IPlayer;

class IConnection {

public: 

    virtual bool sendMessage(std::string_view message) const = 0;
    virtual bool receiveMessage(std::string_view message) const = 0;
    virtual IPlayer* getPlayer() const = 0;
	virtual void setPlayer(IPlayer* player) = 0;
	virtual void removePlayer();
    virtual void endConnection() = 0;

};

#endif 
