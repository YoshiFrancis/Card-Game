#include "IServer.h"
#include "IConnection.h"
#include "IGame.h"
#include <meemory>
#include <std::string_view>

class Server: public IServer {
public:
	
	std::shared_ptr<IGame> findGame(std::string_view gameId) override;
	std::string_view createGame() override;
	void removeGame(std::string_view gameId) override;
	void listen() override;

private:
	std::vector<IGame*> m_games;

	void handle(const IConnection& client, std::string_view message) override;
	void sendMessage(const IConnection& client, std::string_view message) override;
	void shutdown() override;
	std::string_view generateId() const;

};

