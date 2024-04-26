#include "CardGame.h"
#include "IPlayer.h"
#include "IClient.h"
#include "IServer.h"
#include <string_view>
#include <iostream>
#include <algorithm>

bool isAccepting = true;

void CardGame::startGame(IPlayer& player) {
	auto player = CardGame::addPlayer(client);
	CardGame::sendMessage(player, "What game would you like to play");
	std::string_view gameType{};
	while (gameType != "Uno") {
		CardGame::sendMessage(player, "What game would you like to play: Uno");
		gameType = waitForMessage(player);
	}
	m_deck.createDeck(type);
	// m_gamerunner = createRunner(type) --> for future to make the interfacing for runni =ng different card games easier
	// would also potentially move the deck into the game runner as well
    waitForPlayers();
	CardGame::sendMessageAll("Now beginning the game...");
}

void CardGame::runGame() {
	CardGame::sendMessageAll("Starting game...\n");
	while (m_winner == "") {
		std::for_each(m_players.begin(), m_players.end(), askPlayerForMove);
	}
}

void CardGame::endGame() {
	if (m_winner != "") {
		CardGame::sendMessageAll("The winner is " + m_winner "!\n");
	} else {
		CardGame::sendMessageAll("The game will end with no winner...");
	}
	CardGame::sendMessageAll("Ending game...\n");
}

void CardGame::handle(Message message) {
	auto player = container.findPlayer(message.username);
	if (message.flag == 'P') { // play (do action)
		// simulate the game...
	} else if (message.flag == 'J') { // join game
		std::string_view playerName = CardGame::addPlayer(message.client);
		CardGame::sendMessageAll(playerName + " has joined the game!");
	} else if (message.flag == 'L') { // leave game
		CardGame::sendMessageAll(player.getUsername() + " has left the game.");
		container.removePlayer(player);
	} else if (message.flag == 'H') { // ask for help
		CardGame::sendMessage(*player, "To play UNO, either draw or play a card. The card must be either of the same color or of the same type.");
	} else if (message.flag == 'V') { // view cards
		CardGame::sendMessage(player, player.getCards());
	} else if (message.flag == 'S') { // start game
		isAccepting = false;
	} else if (message.flag == 'C') { // chat with other players
		CardGame::sendMessageAll(message.message);
	} else if (message.flag == 'N') {
		// no action
	}
}

std::string_view CardGame::addPlayer(std::shared_ptr<IClient> client) {
	Player player { client };
	std::string_view playerName = m_player.addPlayer(std::move(player);
	return playerName;
}

std::string_view CardGame::getId() {
	return m_id;
}

void CardGame::receiveMessage(Message message) override {
	CardGame::handle(message.player.getClient(), message.message);
}

void CardGame::sendMessage(IPlayer& player, std::string_view message) override {
	player.getClient().receiveMessage(message);
}

void CardGame::sendMessageAll(std::string_view message) {
	std::for_each(m_players.getPlayers().begin(), m_players.getPlayers().end(), [&](auto player) { 
		CardGame::sendMessage(player, messaage);
	}
}

void askPlayerForMove(IPlayer& player) {
	Message message = askPlayer(player, "What card will you player or would you like to draw a card?");
	CardGame::handle(message);
}

void CardGame::waitForPlayers() {
	while (isAccepting) {
		CardGame::handle(CardGame::readBuffer());
	}
	CardGame::sendMessageAll("Closing the doors for new players...");
}

std::string_view askPlayer(IPlayer& player, std::string_view message) {
	CardGame::sendMessage(player, message);
	std::string_view response = CardGame::waitForMessage(client);
	return response;
}

std::string_view CardGame::waitForMessage(IPlayer& player) {
	while (true) {
		Message message = CardGame::readBuffer();
		if (message.username == player.getUsername()) 
			return message.message;
		else if (message.message != "")
			CardGame::handle(message);
	}
}

Message CardGame::readBuffer() {
	Message message{};
	if (m_buffer.size() > 0) {
		message = m_buffer[0];
		m_buffer.pop();
	} 
	return message;
}
