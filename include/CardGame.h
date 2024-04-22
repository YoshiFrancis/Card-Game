#ifndef CARDGAME_H
#define CARDGAME_H

#include "IGame.h"
#include "IDeck.h"
#include "IPlayerContainer.h"
#include <memory>
#include <string_view>

class IDeck;
class IPlayerContainer;

class CardGame : public IGame {

public:

	CardGame(std::string_view id = "1")
	: m_id { id }
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
	void addPlayer(std::shared_ptr<IClient> client) override;
    std::string_view getId() override;

private:

    void waitForPlayers();

    std::unique_ptr<IDeck> m_deck{};
    std::unique_ptr<IPlayerContainer> m_players{};
    std::string_view m_id{};


};

#endif
