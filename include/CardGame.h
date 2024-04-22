#ifndef CARDGAME_H
#define CARDGAME_H

#include "IGame.h"

#include <memory>

class IDeck;
class IPlayerContainer;
class IHandler;

class CardGame : public IGame {

public:

	CardGame(std::string_view id = "1", std::shared_ptr<IHandler> handler)
	: m_id { id }, m_handler { handler };
	{
		// create new thread to run the game in
		
		// startGame();
		// runGame();
		// endGame();

		// end of the thread stuff
	}

    void startGame() override;
    void runGame() override;
    void endGame() override;
	void addPlayer(IClient* client) override;
    std::string_view getId() override;

private:

    void waitForPlayers();

    std::unique_ptr<IDeck> m_deck{};
    std::unique_ptr<IPlayerContainer> m_players{};
    std::shared_ptr<IHandler> m_handler{};
    std::string_view m_id{};


};

#endif
