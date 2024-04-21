#include "Server.h"
#include "IGame.h"
#include "../helper.h"
#include <string_view>
#include <memory>
#include <algorithm>

std::shared_ptr<IGame> Server::findGame(std::string_view gameId) override {
	return std::find_if(m_games.being(), m_games.end(), [&](IGame* game) { return game->getId() == gameId; });
}

void Server::createGame(std::string_view type) override {
	m_games.push_back(CardGame(type));
}

void Server::removeGame(std::string_view gameId) override {
	m_games.remove(Server::find_game(gameId));
}

void Server::handle(IClient& client, std::string_view message) {
	m_handler->handle(client, message);
}

std::string_view Server::generateId() {
	return std::to_string(Helper::generateRandomNumber(1, 10000));
}
