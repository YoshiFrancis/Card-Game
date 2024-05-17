#ifndef CARDGAME_H
#define CARDGAME_H

#include "application.h"
#include "ConnectionI.hpp"
#include "PlayerContainer.h"
#include "Deck.h"
#include <string_view>
#include <deque>

class CardGame : public Application {

public:

	CardGame()
	{
	}

	void start() override;
	void end() override;
	void addConns(std::set<conn_ptr>& conns) override;
	void promptUser(std::string message, std::string prompt);
	Application* createApplication() override;

private:
	Deck m_deck{};
	PlayerContainer m_players{};

	void handleMessage(message& msg, conn_ptr conn) override;
	void createPlayers();
	void run();
};

#endif
