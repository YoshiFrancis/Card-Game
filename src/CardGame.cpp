#include "CardGame.h"
#include "IPlayer.h"
#include <string_view>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
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
		advancePlayerIt(1);
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
	if (msg.getFlag() == 'C' || msg.body()[0] == '/') {
		handleCommand(msg, conn);
	}
	else if (conn->isPrompt("Turn")) {
		handleMove(msg, conn);
	}
	else if (conn->isPrompt("ChangeColor")) {
		handleColorChange(msg, conn);
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
	else if (msg.body().substr(0,5) == "/peek") {
		message top_card_msg { "Top Card: " + m_top_card.peek(), 'M' };
		top_card_msg.encode_header();
		conn->deliver(top_card_msg);
	}
	else if (msg.body().substr(0, 6) == "/leave") {
		conn->changeRoom(return_room_);
	}
}

void CardGame::handleMove(message& msg, conn_ptr conn) {
	auto played_card = m_curr_player_iter->playCard(msg.body());
	if (played_card == nullptr) {
		std::cout << "2\n";
		message error_msg { "You do not own that card! Do /hand to view current cards or /draw if you do not have any valid cards", 'M' };
		error_msg.encode_header();
		conn->deliver(error_msg);
	}
	else if (!m_top_card.replace(played_card)) {
		std::cout << "3\n";
		message error_msg { "You can't place that card!", 'M' };
		m_curr_player_iter->drawCards( std::move(played_card) );
		error_msg.encode_header();
		conn->deliver(error_msg);
	}
	else {
		std::cout << "4\n";
		handleCard(msg, conn);
	}
}

void CardGame::handleCard(message& msg, conn_ptr conn) {
	alert(conn->getUsername() + " played the card " + msg.body());
	std::string symbol = m_top_card.getSymbol();
	conn->setPrompt("None");
	std::string card_msg = "";
	if (symbol == "plus4") {
		promptPlayer("What color would you like to change to?", "ColorChange", *m_curr_player_iter);
		advancePlayerIt(1);
		auto drawn_cards = m_deck.drawCards(4);
		m_curr_player_iter->drawCards(std::move(drawn_cards));
		card_msg = m_curr_player_iter->getUsername() + " draws 4 and has been skipped due to " + conn->getUsername();
	} else if (symbol == "change") {
		promptPlayer("What color would you like to change to?", "ColorChange", *m_curr_player_iter);
	} else if (symbol == "skip") {
		advancePlayerIt(1);
		card_msg = m_curr_player_iter->getUsername() + " has been skipped by " + conn->getUsername();
	} else if (symbol == "reverse") {
		isReversed = !isReversed;
		card_msg = "Order has been reversed!";
	} else if (symbol == "plus2") {
		advancePlayerIt(1);
		auto drawn_cards = m_deck.drawCards(2);
		m_curr_player_iter->drawCards(std::move(drawn_cards));
		card_msg = m_curr_player_iter->getUsername() + " draws 2 and has been skipped due to " + conn->getUsername();
	} 
	advancePlayerIt(1);
	if (conn->isPrompt("None")) {
		askPlayerForMove(*m_curr_player_iter);
	}
	if (card_msg != "") {
		alert(card_msg);
	}
}
	
void CardGame::handleColorChange(message& msg, conn_ptr conn) {
	auto& colorsVec = UnoCard::getAllColors();
	auto colorIt = std::find_if(colorsVec.begin(), colorsVec.end(), 
		[msg] (const std::string& color) 
		{
			return color == msg.body();
		});
	if (colorIt != colorsVec.end() && *colorIt != "all") {
		m_top_card.setColor(msg.body());
		alert("Color has been changed to " + msg.body() + " by " + conn->getUsername());
		conn->setPrompt("None");
		askPlayerForMove(*m_curr_player_iter);
	} else {
		message error_msg { "Invalid color has been entered. Please enter one of the following: yellow, blue, red, green", 'M' };
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

void CardGame::advancePlayerIt(int n) {
	for (int counter = 0; counter < n; ++counter) {
		int step = 1;
		if (isReversed) {
			step = -1;
		}
		std::advance(m_curr_player_iter, step);
		auto end = isReversed ? std::prev(m_players.begin()) : m_players.end();
		if (m_curr_player_iter == end) {
			m_curr_player_iter = isReversed ? std::prev(m_players.end()) : m_players.begin();
		}
	}
}
