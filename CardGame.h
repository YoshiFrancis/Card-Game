#ifndef CARDGAME_H
#define CARDGAME_H

#include "IGame.h"

#include <memory>

class IDeck;
class IPlayerContainer;
class ICommunicator;

class CardGame : public IGame {

public:

    void startGame();
    void runGame();
    void endGame();

private:

    std::unique_ptr<IDeck> m_deck{};
    std::unique_ptr<IPlayerContainer> m_players{};
    std::unique_ptr<ICommunicator> m_communicator{};


};

#endif