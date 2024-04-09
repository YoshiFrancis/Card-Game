#ifndef IGAME_H
#define IGAME_H

#include <string_view>

class IServer;

class IGame {

    virtual void startGame() = 0;
    virtual void runGame() = 0;
    virtual void endGame() = 0;
    virtual IServer* getServer() = 0;
    
};

#endif