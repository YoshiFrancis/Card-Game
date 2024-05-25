#include "Player.h"
#include <vector>
#include <string>
#include <iterator>
#include <set>

class ConnectionI;

class PlayerContainer {

public:

	void addConns(std::set<conn_ptr>& conns);
	void removePlayer(std::string name);
	player_iter findPlayer(std::string name);
	Player& getPlayer(std::string name);
	player_iter end();
	player_iter begin();
	int getPlayerCount();
	int getMaxCount();

	~PlayerContainer() {};

private:
	bool addPlayer(Player player);
	std::list<Player> m_players {};
	int m_count = 0;
	int m_maxCount = 8;
};
