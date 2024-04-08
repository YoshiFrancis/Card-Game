#ifndef IGAME_H
#define IGAME_H

#include <string_view>

class IGame {

    virtual void startGame() = 0;
    virtual void runGame() = 0;
    virtual void endGame() = 0;
    
};

#endif