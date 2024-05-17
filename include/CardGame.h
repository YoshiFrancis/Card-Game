#ifndef CARDGAME_H
#define CARDGAME_H

#include "application.h"
#include "ConnectionI.hpp"
#include "PlayerContainer.h"
#include "Deck.h"
#include <string_view>
#include <string>
#include <deque>

class CardGame : public Application {

public:

	void start(std::set<conn_ptr>& conns) override;
	void end() override;
	void promptUser(std::string message, std::string prompt);
	std::string getDescription() override;
	Application* createApplication() override;

private:
	Deck m_deck{};
	PlayerContainer m_players{};

	void addConns(std::set<conn_ptr>& conns);
	void handleMessage(message& msg, conn_ptr conn) override;
	void createPlayers();
	void run();
};

#endif
