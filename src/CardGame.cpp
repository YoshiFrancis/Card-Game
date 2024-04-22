#include "CardGame.h"
#include "IPlayer.h"
#include "IClient.h"
#include "IServer.h"
#include <std::string_view>
#include <iostream>
#include <algorithm>

void CardGame::startGame(IPlayer& player) {
	addPlayer(client);
	sendMessage(client, "What game would you like to play");
	std::string_view gameType = waitForMessage();
	m_deck.createDeck(type);
    waitForPlayers();
    std::cout << "Now beginning the game...";
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
	}
	CardGame::sendMessageAll("Ending game...\n");
}

void CardGame::addPlayer(IPlayer&& player) {
	m_players.addPlayer(player);
}

std::string_view CardGame::getId() {
	return m_id;
}

void CardGame::receiveMessage(IPlayer& player, std::string_view message) override {
	CardGame::handle(player.getClient(), message);
}

void CardGame::sendMessage(IPlayer& player, std::string_view message) override {
	player.getClient().receiveMessage(message);
}

void CardGame::sendMessaggeAll(std::string_view message) {
	std::for_each(m_players.getPlayers().begin(), m_players.getPlayers().end(), [&](auto player) { 
		CardGame::sendMessage(player, messaage);
	}
}

void askPlayerForMove(IPlayer& player) {
	std::string_view response = askPlayer(player, "What card will you player or would you like to draw a card?");
	CardGame::handle(client, response);
}

void CardGame::waitForPlayers() {
    /*
    while m_communicating is waiting for players
        add new player
        announce to all current players the new player
    */
}

std::string_view askPlayer(IPlayer& player, std::string_view message) {
	CardGame::sendMessage(client, message);
	std::string_view response = CardGame::waitForResponse(client);
	return response;
}

std::string_view CardGame::waitForResponse() {
	// do a blocking function to get player response
	// if you do not want it to be blocking, make the askPlayer function occur in a separate thread
}


