#ifndef CLIENT_H
#define CLIENT_H

#include "IClient.h"
#include "IPlayer.h"
#include "IHandler.h"
#include <memory>

class Client : public IClient {

public:
	Client(std::shared_ptr<IHandler> handler) : m_handler { handler }
	{
		std::cout << "Joining server...\n";
	}
	bool sendMessage(std::string_view message) override;
	void receiveMessage(std::string_view message) override;
	IPlayer* getPlayer() override;
	void setPlayer(IPlayer* player) override;
	void removePlayer() override;
	void endConnection() override;

private:
	IPlayer* m_player;
	std::shared_ptr<IHandler> m_handler;

	
};

#endif
