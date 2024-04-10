#ifndef ISERVER_H
#define ISERVER_H

#include <memory>
#include <string_view>

class IGame;

class IServer {

    virtual std::unique_ptr<IGame> findGame(std::string_view gameIdentifier) = 0;
    virtual void createGame() = 0;
    virtual void removeGame(int gameId) = 0;

};

#endif
