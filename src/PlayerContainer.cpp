#include "PlayerContainer.h"
#include "Player.h"
#include <vector>
#include <string_view>
#include <iterator>
#include <algorithm>


bool PlayerContainer::addPlayer(Player player) override {
	if (m_count >= m_maxCount)
		return false;
	m_players.push_back(std::move(player));
	++m_count;
	return true;
}

bool PlayerContainer::removePlayer(std::string_view name) override {
	if (m_count == 0) 
		return false;
	auto playerIt = PlayerContainer::findPlayer(name);
	if (playerIt == m_players.end())
		return false;
	m_players.erase(playerIt);
	--m_count;
	return true;
}

std::vector<Player>::iterator PlayerContainer::findPlayer(std::string_view name) override {
	return std::find_if(m_players.begin(), m_players.end(), [&](auto player) { 
		return player.getName() == name;
	}
}

std::vecctor<Player> getPlayers() override {
	return m_players;
}

int PlayerContainer::getPlayerCount() {
	return m_count;
}
