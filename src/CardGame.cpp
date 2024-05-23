#include "CardGame.h"
#include "IPlayer.h"
#include <string_view>
#include <iostream>
#include <algorithm>
#include <set>
#include <cassert>

#define STARTING_AMOUNT 5

Application* CardGame::createApplication(Room* lobby) {
	return new CardGame(lobby);
}

void CardGame::start(std::set<conn_ptr>& connections) {
	addConns(connections);
	std::string_view type {"Uno"};
	m_deck.createDeck("Uno");
	std::for_each(m_players.begin(), m_players.end(),
		[&](auto& player)
		{
			auto cards = m_deck.drawCards(STARTING_AMOUNT); 
			player.drawCards(std::move(cards));
		});
	run();
}

void CardGame::leave(conn_ptr conn) {
	alert(conn->getUsername() + " is leaving!");
	if (conn->isPrompt("Turn")) {
		advancePlayerTurn();
		conn->setPrompt("None");
	}
	m_players.removePlayer(conn->getUsername());
	Room::leave(conn);
	askPlayerForMove(*m_curr_player_iter);
}

void CardGame::run() {
	askPlayerForMove(*m_curr_player_iter);
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
	m_curr_player_iter = m_players.begin();
}

void CardGame::handleMessage(message& msg, conn_ptr conn) {
	std::cout << "Prompt: " << conn->getPrompt() << "\n";
	if (msg.getFlag() == 'C') {
		handleCommand(msg, conn);
	}
	else if (conn->isPrompt("Turn")) {
		conn->setPrompt("None");
		alert(conn->getUsername() + " played the card " + msg.body());
		advancePlayerTurn();
		askPlayerForMove(*m_curr_player_iter);
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
		Player& player = m_players.getPlayer(conn->getUsername());
		message hand_info_msg { "Your cards -\n" + player.getCards(), 'M' };
		hand_info_msg.encode_header();
		conn->deliver(hand_info_msg);
	}
	else if (msg.body().substr(0, 5) == "/draw") {
		Player& player = m_players.getPlayer(conn->getUsername());

		auto drawn_card = m_deck.drawCards(1);
		message drawn_cards_msg { "Card drawn: " + drawn_card[0]->getName(), 'M' };

		player.drawCards(std::move(drawn_card));

		drawn_cards_msg.encode_header();
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

void CardGame::handleMove(message& msg, conn_ptr conn) {
	auto played_card = m_curr_player_iter->playCard(msg.body());
	if (played_card != nullptr) {
		message error_msg { "You do not own that card! Do /hand to view current cards or /draw if you do not have any valid cards", 'M' };
		error_msg.encode_header();
		conn->deliver(error_msg);
	}
	else if (!m_top_card.replace(played_card)) {
		message error_msg { "You can't place that card!", 'M' };
		error_msg.encode_header();
		conn->deliver(error_msg);
	}
	/*
		if(!m_top_card.replace(played_card)) {
			m_curr_player_iter->drawCards({ std::move(played_card) });
			askPlayerForMove(*m_curr_player_iter);
		}
		*/
	else {
		message error_msg { "You played an invalid card! Do /hand to view your current cards or /draw if you do not have any valid cards", 'M' };
		error_msg.encode_header();
		conn->deliver(error_msg);
	}
}

std::string CardGame::getRoomInfo() {
	std::string info_string {"CardGame: "};
	info_string += "\nGame: Uno";
	info_string += "\nTotal players: " + std::to_string(m_players.getPlayerCount());
	info_string += "\nPlayers: ";
	std::for_each(m_players.begin(), m_players.end(),
		[&info_string](Player& player)
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

void CardGame::advancePlayerTurn() {
	m_curr_player_iter = std::next(m_curr_player_iter, 1);
	if (m_curr_player_iter == m_players.end()) {
		m_curr_player_iter = m_players.begin();
	}
}
