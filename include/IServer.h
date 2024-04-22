#ifndef ISERVER_H
#define ISERVER_H

#include <memory>
#include <string_view>

class IGame;

class IServer {

    virtual std::shared_ptr<IGame> findGame(std::string_view gameId) = 0;
    virtual void createGame() = 0;
    virtual void removeGame(std::string_view gameId) = 0;
	virtual void listen() = 0;

};

#endif
