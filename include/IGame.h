#ifndef IGAME_H
#define IGAME_H

#include "IClient.h"
#include "IServer.h"
#include <memory>
#include <string_view>

class IGame {

    virtual void startGame() = 0;
    virtual void runGame() = 0;
    virtual void endGame() = 0;
	virtual void addPlayer(std::shared_ptr<IClient> client);
    virtual std::shared_ptr<IServer> getServer() = 0;
    virtual std::string_view getId();
	virtual void receiveMessage(std::shared_ptr<IClient> client, std::string_view message) = 0;
	virtual void sendMessage(std::shared_ptr<IClient> client, std::string_view message) = 0;
    
};

#endif
