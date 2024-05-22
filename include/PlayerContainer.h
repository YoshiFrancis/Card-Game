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
	void removePlayer(std::string name) override;
	player_iter findPlayer(std::string name) override;
	Player& getPlayer(std::string name);
	player_iter end();
	player_iter begin();
	int getPlayerCount();
	int getMaxCount();

	~PlayerContainer() {};

private:
	std::list<Player> m_players {};
	int m_count = 0;
	int m_maxCount = 8;
};
