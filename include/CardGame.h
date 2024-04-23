#ifndef CARDGAME_H
#define CARDGAME_H

#include "IGame.h"
#include "IServer.h"
#include "IClient.h"
#include "PlayerContainer.h"
#include "Deck.h"
#include <memory>
#include <string_view>

class CardGame : public IGame {

public:

	CardGame(std::string_view id = "1")
	: m_id { id }
	{
		// create new thread to run the game in
		
		// startGame();
		// runGame();
		// endGame();

		// end of the thread stuff
	}

    void startGame() override;
    void runGame() override;
    void endGame() override;
	void addPlayer(std::shared_ptr<IClient> client) override;
	std::shared_ptr<IServer> getServer() override;
    std::string_view getId() override;
	void receiveMessage(std::shared_ptr<IClient> client, std::string_view message) override;

private:

    void waitForPlayers();
	void sendMessage(std::shared_ptr<IClient> client, std::string_view message) override;

    Deck m_deck{};
    PlayerContainer m_players{};
	std::shared_ptr<IServer> m_server{};
    std::string_view m_id{};




};

#endif
