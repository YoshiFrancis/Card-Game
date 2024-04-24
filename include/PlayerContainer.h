#include "IPlayerContainer.h"
#include "Player.h"
#include <vector>
#include <string_view>
#include <iterator>

class PlayerContainer : public IPlayerContainer {

public:

	bool addPlayer(Player player) override;
	bool removePlayer(std::string_view name) override;
	std::vector<Player>::iterator findPlayer(std::string_view name) override;
	std::vector<Player>& getPlayers() override;
	int getPlayerCount();
	int getMaxCount();

	~PlayerContainer() {};

private:
	std::vector<Player> m_players {};
	int m_count = 0;
	int m_maxCount = 8;
};
