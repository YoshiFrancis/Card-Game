#include "IPlayerContainer.h"
#include "Player.h"
#include <vector>
#include <string>
#include <iterator>
#include <set>

class ConnectionI;

class PlayerContainer : public IPlayerContainer {

public:

	bool addPlayer(Player player) override;
	void addConns(std::set<conn_ptr>& conns);
	bool removePlayer(std::string name) override;
	std::vector<Player>::iterator findPlayer(std::string name) override;
	std::vector<Player>& getPlayers() override;
	int getPlayerCount();
	int getMaxCount();

	~PlayerContainer() {};

private:
	std::vector<Player> m_players {};
	int m_count = 0;
	int m_maxCount = 8;
};
