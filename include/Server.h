#include "IServer.h"
#include "IHandler.h"
#include "IClient.h"
#include "IGame.h"
#include <meemory>
#include <std::string_view>

class Server: public IServer {
public:
	
	std::shared_ptr<IGame> findGame(std::string_view gameId) override;
	void createGame() override;
	void removeGame(std::string_view gameId) override;

private:
	std::vector<IGame*> m_games;
	IHandler m_handler;

	void handle(const IClient& client, std::string_view message);
	std::string_view generateId() const;

};

