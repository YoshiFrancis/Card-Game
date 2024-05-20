#include "CardGame.h"
#include "IPlayer.h"
#include <string_view>
#include <iostream>
#include <algorithm>
#include <set>
#include <cassert>

Application* CardGame::createApplication(Room* lobby) {
	return new CardGame(lobby);
}

void CardGame::start(std::set<conn_ptr>& connections) {
	addConns(connections);
	std::string_view type {"Uno"};
	m_deck.createDeck("Uno");
	run();
}

void CardGame::run() {
	askPlayerForMove(m_players.getPlayers()[curr_player_idx]);
}

void CardGame::end() {
	std::cout << "card game ending\n";
}

std::string CardGame::getDescription() {
	return "Uno Game";
}

void CardGame::addConns(std::set<conn_ptr> connections) {
	connections_ = connections;
	m_players.addConns(connections_);
	std::for_each(connections_.begin(), connections_.end(), 
		[this](conn_ptr conn)
		{
			conn->changeRoom(this);
		});
}

void CardGame::handleMessage(message& msg, conn_ptr conn) {
	if (conn->isPrompt("Turn")) {
		alert(conn->getUsername() + " played the card " + msg.body());
		conn->setPrompt("None");
		if (curr_player_idx >= m_players.getPlayerCount())
		{
			curr_player_idx = 0;
		}
		askPlayerForMove(m_players.getPlayers()[curr_player_idx++]);
	}
}

void CardGame::promptPlayer(std::string player_msg, std::string prompt, Player& player) {
	player.getConn()->setPrompt(prompt);
	message msg { player_msg, 'Q' };
	msg.encode_header();
	player.getConn()->deliver(msg);
}

void CardGame::askPlayerForMove(Player& player) {
	promptPlayer("Your turn!", "Turn", player);
}
	
	
