#ifndef CONNECTION_H
#define CONNECTION_HH

#include "IConnection.h"
#include "IPlayer.h"
#include "IHandler.h"
#include <memory>

class Client : public IConnection {

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
