#ifndef ISERVER_H
#define ISERVER_H

#include <memory>
#include <string_view>

class IGame;

class IServer {

    virtual std::shared_ptr<IGame> findGame(std::string_view gameId) = 0;
    virtual std::string_view createGame() = 0; // returns gameID
    virtual void removeGame(std::string_view gameId) = 0;
	virtual void listen() = 0;
	virtual void handle(const IClient& client, std::string_view message) = 0;
	virtual void shutdown() = 0;

};

#endif
