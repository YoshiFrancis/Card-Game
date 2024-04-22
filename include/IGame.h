#ifndef IGAME_H
#define IGAME_H

#include <string_view>

class IServer;
class IClient;

class IGame {

    virtual void startGame() = 0;
    virtual void runGame() = 0;
    virtual void endGame() = 0;
	virtual void addPlayer(std::shared_ptr<IClient> client);
    virtual IServer* getServer() = 0;
    virtual std::string_view getId();
    
};

#endif
