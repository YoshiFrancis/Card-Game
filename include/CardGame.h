#ifndef CARDGAME_H
#define CARDGAME_H

#include "application.h"
#include "ConnectionI.hpp"
#include "PlayerContainer.h"
#include "Deck.h"
#include "UnoTopCard.h"
#include <string_view>
#include <string>
#include <deque>

class CardGame : public Application {

public:

	CardGame(Room* lobby) 
		: Application(lobby)
	{
	}

	void start(std::set<conn_ptr>& conns) override;
	void end() override;
	void promptUser(std::string message, std::string prompt);
	void leave(conn_ptr) override;
	std::string getDescription() override;
	Application* createApplication(Room* lobby) override;

private:
	Deck m_deck{};
	PlayerContainer m_players{};
	UnoTopCard m_top_card{};
	bool isPlaying = true;
	void askPlayerForMove(Player& player);
	player_iter m_curr_player_iter;

	void promptPlayer(std::string player_msg, std::string prompt, Player& player);
	void addConns(std::set<conn_ptr> connections);
	void handleMessage(message& msg, conn_ptr conn) override;
	void handleCommand(message& msg, conn_ptr conn) override;
	void handleMove(message& msg, conn_ptr conn);
	void handleCard(message& msg, conn_ptr conn);
	handleColorChange(message& msg, conn_ptr conn);
	void advancePlayerTurn();
	std::string getRoomInfo() override;
	std::string getCommands() override;
	void createPlayers();
	void run();
};

#endif
