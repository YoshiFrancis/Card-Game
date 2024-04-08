#ifndef CARDGAME_H
#define CARDGAME_H

#include "IGame.h"

class IDeck;
class IPlayerContainer;

class CardGame : public IGame {

public:

    void startGame();
    void runGame();
    void endGame();

private:

    IDeck m_deck;
    IPlayerContainer m_players;

};

#endif