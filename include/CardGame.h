#ifndef CARDGAME_H
#define CARDGAME_H

#include "application.h"
#include "ConnectionI.hpp"
#include "PlayerContainer.h"
#include "Deck.h"
#include "UnoTopCard.h"
#include <string>

class CardGame : public Application {

public:

	CardGame(Room* lobby) 
		: Application(lobby)
	{
	}

	void start(std::set<conn_ptr>& conns) override;
	void end() override;
	void reset() override;
	void leave(conn_ptr) override;
	std::string getDescription() override;
	Application* createApplication(Room* lobby) override;

private:
	Deck m_deck{};
	PlayerContainer m_players{};
	UnoTopCard m_top_card{};
	bool isPlaying = true;
	bool isReversed = false;
	bool hasWinner = false;
	player_iter m_curr_player_iter;
	player_iter m_winner;

	void askPlayerForMove(Player& player);
	void promptPlayer(std::string player_msg, std::string prompt, Player& player);
	void addConns(std::set<conn_ptr> connections);
	void handleMessage(message& msg, conn_ptr conn) override;
	void handleCommand(message& msg, conn_ptr conn) override;
	void handleMove(message& msg, conn_ptr conn);
	void handleCard(message& msg, conn_ptr conn);
	void handleColorChange(message& msg, conn_ptr conn);
	void advancePlayerIt(int n=1);
	std::string getRoomInfo() override;
	std::string getCommands() override;
	void run();
};

#endif
