#ifndef CARDGAME_H
#define CARDGAME_H

#include "application.h"
#include "ConnectionI.h"
#include "PlayerContainer.h"
#include "Deck.h"
#include <string_view>
#include <deque>

class CardGame : public Application {

public:

	CardGame(std::set<conn_ptr>& connections)
	: 
	{
		// create new thread to run the game in
		
		// startGame();
		// runGame();
		// endGame();

		// end of the thread stuff
	}

	void start() override;
	void end() override;
	void promptUser(std::string message, std::string prompt);
	std::string_view getId() override;

private:
	Deck m_deck{};
	PlayerContainer m_players{};
	std::string_view m_id{};

	void handleMessage(message& msg, conn_ptr conn) override;
	void createPlayers();
	void run();
};

#endif
