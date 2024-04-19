#ifndef CARDGAME_H
#define CARDGAME_H

#include "IGame.h"

#include <memory>

class IDeck;
class IPlayerContainer;
class IHandler;

class CardGame : public IGame {

public:

    void startGame() override;
    void runGame() override;
    void endGame() override;
	void addPlayer(IClient* client) override;
    int getId() override;

private:

    void waitForPlayers();

    std::unique_ptr<IDeck> m_deck{};
    std::unique_ptr<IPlayerContainer> m_players{};
    std::unique_ptr<IHandler> m_handler{};
    int m_id{};


};

#endif
