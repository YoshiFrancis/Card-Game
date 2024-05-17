#include "CardGame.h"
#include "IPlayer.h"
#include <string_view>
#include <iostream>
#include <algorithm>

static void askPlayerForMove(Player& player);
static void promptPlayer(std::string player_msg, std::string prompt, Player& player);

Application* CardGame::createApplication() {
	return new CardGame();
}

void CardGame::start(std::set<conn_ptr>& conns) {
	addConns(conns);
	std::string_view type {"Uno"};
	m_deck.createDeck("Uno");
	// m_gamerunner = createRunner(type) --> for future to make the interfacing for runni =ng different card games easier
	// would also potentially move the deck into the game runner as well
	alert("Now beginning the game...");
	run();
}

void CardGame::run() {
	std::cout << "card game running\n";
	std::for_each(m_players.getPlayers().begin(), m_players.getPlayers().end(), askPlayerForMove);
	/*
	while (m_winner == "") {
	}
	*/
}

void CardGame::end() {
	std::cout << "card game ending\n";
}

std::string CardGame::getDescription() {
	return "Uno Game";
}

void CardGame::addConns(std::set<conn_ptr>& conns) {
	connections_ = conns;
	// create player for each connections)
}

void CardGame::handleMessage(message& msg, conn_ptr conn) {
	std::cout << msg.body() << "\n";
}

void promptPlayer(std::string player_msg, std::string prompt, Player& player) {
	player.getConn()->setPrompt(prompt);
	message msg { player_msg, 'Q' };
	msg.encode_header();
	player.getConn()->deliver(msg);
}

void askPlayerForMove(Player& player) {
	promptPlayer("Your turn!", "Turn", player);
}
	
	
