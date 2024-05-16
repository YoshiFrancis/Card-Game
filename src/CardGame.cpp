#include "CardGame.h"
#include "IPlayer.h"
#include <string_view>
#include <iostream>
#include <algorithm>

void CardGame::start() {
	std::cout << "card game starting\n";
	m_players.addClients(connections_);
	std::string_view type {"Uno"};
	m_deck.createDeck(type);
	// m_gamerunner = createRunner(type) --> for future to make the interfacing for runni =ng different card games easier
	// would also potentially move the deck into the game runner as well
	deliverAll("Now beginning the game...");
	run();
}

void CardGame::run() {
	std::cout << "card game running\n";
	std::for_each(m_players.begin(), m_players.end(), askPlayerForMove);
	/*
	while (m_winner == "") {
	}
	*/
}

void CardGame::end() {
	std::cout << "card game ending\n";
}

std::string_view CardGame::getId() {
	return m_id;
}

void handleMessage(message& msg, conn_ptr conn) {
	std::cout << msg.body() << "\n";
}

void promptPlayer(std::string message, std::string prompt, Player& player) {
	player.getConn()->setPrompt(prompt);
	message msg { message, 'Q' };
	msg.encode_header();
	player.getConn()->deliver(msg);
}

void askPlayerForMove(Player& player) {
	promptPlayer("Your turn!", "Turn", player);
}
	
	
