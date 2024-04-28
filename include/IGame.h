#ifndef IGAME_H
#define IGAME_H

#include "IConnection.h"
#include "IServer.h"
#include "IPlayer.h"
#include <memory>
#include <string_view>

class IGame {
public:
	struct {
		std::string_view message;
		std::string_view username;
		char flag;
		std::shared_ptr<IConnection> client = nullptr;
	} Message;

    virtual void startGame() = 0;
    virtual void runGame() = 0;
    virtual void endGame() = 0;
	virtual void addPlayer(std::shared_ptr<IConnection> client);
    virtual std::shared_ptr<IServer> getServer() = 0;
    virtual std::string_view getId();
	virtual void receiveMessage(Message message) = 0;
	virtual void sendMessage(Message message) = 0;
    
};

#endif
