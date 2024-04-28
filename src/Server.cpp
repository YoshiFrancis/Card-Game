#include "Server.h"
#include "IGame.h"
#include "../helper.h"
#include <string_view>
#include <memory>
#include <algorithm>

std::shared_ptr<IGame> Server::findGame(std::string_view gameId) override {
	return std::find_if(m_games.being(), m_games.end(), [&](IGame* game) { return game->getId() == gameId; });
}

std::string_view Server::createGame(std::string_view type) override {
	
	std::string_view gameId = Server::generateId();
	m_games.push_back(CardGame(type, gameId));
	return gameId;
}

void Server::removeGame(std::string_view gameId) override {
	m_games.remove(Server::find_game(gameId));
}

void Server::listen() override {
	// listen
	// accept request
	// will need to research how to listen and accept request
	Server::handle(client, message);
}

void Server::handle(IConnection& client, std::string_view message) {
	if (message[0] == 'J') {
		// user is joining the game
		// will need to ask for username
		// bind client to a player class
		client.setPlayer(m_game->addPlayer(client));

	} else if (message[0] == 'P') {
		// user is playing card/game
		// access the client's player class to play game
		client.getPlayer()->playCard();
	} else if (message[0] == 'H') {
		// user is asking for instructions on how to play
		// send client a message of helpful text (probably read from a file)
		Server::sendMessage(client, "HELP");
	} else if (message[0] == 'L') {
		// client wants to leave, so end connection
		Server::endConnection(client);
	} else if (message[0] == 'C') {
		// client is requestion to create a game
		std::string gameId = Server::createGame("Uno");
		auto game = Server::findGame(gameId);
		game->addPlayer(client);
	}
	else {
		// user sent invalid message
		// send error message to client
		Server::sendMessage(client, "Invalid input");
	}
}

void Server::sendMessage(const IConnection& client, std::string_view message) {

	// i do not know how sockets work on asio
	// i shall ahve to do a little bit of reading ;)
}

void Server::endConnection(const IConnection& client) {

	// need to research how sockets and all that work on asio

}

void Server::endGame(IGame* game) {
	game->endGame();
}

void Server::shutdown() override {
	std::for_each(m_games.begin(), m_games.end(), Server::endGame);
}

std::string_view Server::generateId() {
	return std::to_string(Helper::generateRandomNumber(1, 10000));
}
