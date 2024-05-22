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

void CardGame::leave(conn_ptr conn) {
	alert(conn->getUsername() + " is leaving!");
	if (conn->isPrompt("Turn")) {
		askPlayerForMove(m_players.getPlayers()[curr_player_idx++]);
	}
	m_players.removePlayer(conn->getUsername());
	Room::leave(conn);
	conn->setPrompt("None");
	std::cout << "HELLO\n";
	for (auto& player : m_players.getPlayers()) {
		std::cout << player.getUsername() << " ";
	}
}

void CardGame::run() {
	askPlayerForMove(m_players.getPlayers()[curr_player_idx++]);
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
	if (msg.getFlag() == 'C') {
		handleCommand(msg, conn);
	}
	else if (conn->isPrompt("Turn")) {
		alert(conn->getUsername() + " played the card " + msg.body());
		conn->setPrompt("None");
		if (curr_player_idx >= m_players.getPlayerCount())
		{
			curr_player_idx = 0;
		}
		askPlayerForMove(m_players.getPlayers()[curr_player_idx++]);
	}
	else {
		Room::handleMessage(msg, conn);
	}
}

void CardGame::handleCommand(message& msg, conn_ptr conn) {
	if (msg.body().substr(0, 5) == "/info") {
		std::string info_string = getRoomInfo();
		message info_msg { info_string, 'M' };
		info_msg.encode_header();
		conn->deliver(info_msg);
	}
	else if (msg.body().substr(0, 5) == "/hand") {
		auto player = m_players.findPlayer(conn->getUsername());
		message hand_info_msg { "Your cards -\n" + player->getCards(), 'M' };
		hand_info_msg.encode_header();
		conn->deliver(hand_info_msg);
	}
	else if (msg.body().substr(0, 5) == "/draw") {
		auto player = m_players.findPlayer(conn->getUsername());
		auto drawn_card = m_deck.drawCards(1);
		player->drawCards(std::move(drawn_card));
		message drawn_cards_msg { "You received: " + drawn_card[0]->getName(), 'M'};
		conn->deliver(drawn_cards_msg);
	}
	else if (msg.body().substr(0,5) == "/help") {
		std::string commands_string = getCommands();
		message commands_msg { commands_string, 'M' };
		commands_msg.encode_header();
		conn->deliver(commands_msg);
	}
	else if (msg.body().substr(0, 6) == "/leave") {
		conn->changeRoom(return_room_);
	}
}

std::string CardGame::getRoomInfo() {
	std::string info_string {"CardGame: "};
	info_string += "\nGame: Uno";
	info_string += "\nTotal players: " + std::to_string(m_players.getPlayerCount());
	info_string += "\nPlayers: ";
	std::for_each(m_players.getPlayers().begin(), m_players.getPlayers().end(),
		[&info_string](auto& player)
		{
			info_string += " " + player.getUsername();
		});
	return info_string; 
}

std::string CardGame::getCommands() {
	std::string commands_string {"CardGame: "};
	commands_string += "\n/info : get info of the room";
	commands_string += "\n/hand : view your current hand of cards";
	commands_string += "\n/draw : draw a new card when it is your turn";
	commands_string += "\n/help : view list of commands";
	commands_string += "\nleave : leave game and go back to lobby";
	return commands_string;
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
	
	
