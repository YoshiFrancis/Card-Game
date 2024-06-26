#include "PlayerContainer.h"
#include "Player.h"
#include "ConnectionI.hpp"
#include <list>
#include <string>
#include <iterator>
#include <algorithm>
#include <memory>


bool PlayerContainer::addPlayer(Player player)  {
	if (m_count >= m_maxCount)
		return false;
	m_players.push_back(std::move(player));
	++m_count;
	return true;
}

void PlayerContainer::addConns(std::set<conn_ptr>& conns) {
	std::for_each(conns.begin(), conns.end(), 
		[&](conn_ptr conn)
		{
			m_players.emplace_back(conn, conn->getUsername());
			++m_count;
		});
}

void PlayerContainer::removePlayer(std::string name)  {
	auto playerIt = PlayerContainer::findPlayer(name);
	m_players.erase(playerIt);
	--m_count;
}

player_iter PlayerContainer::end() {
	return m_players.end();
}

player_iter PlayerContainer::begin() {
	return m_players.begin();
}

player_iter PlayerContainer::findPlayer(std::string name)  {
	return std::find_if(m_players.begin(), m_players.end(), [&](auto& player) { 
		return player.getUsername() == name;
	});
}

Player& PlayerContainer::getPlayer(std::string name) {
	return *findPlayer(name);
}

int PlayerContainer::getPlayerCount() {
	return m_count;
}

int PlayerContainer::getMaxCount() {
	return m_maxCount;
}
