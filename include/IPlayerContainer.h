#ifndef IPLAYERCONTAINER_H
#define IPLAYERCONTAINER_H

#include "Player.h"
#include <string>
#include <vector>
#include <iterator>

class Player;

class IPlayerContainer {

public:
	virtual ~IPlayerContainer() {}
	virtual bool addPlayer(Player player) = 0;
	virtual bool removePlayer(std::string name) = 0;
	virtual std::vector<Player>::iterator findPlayer(std::string name) = 0;
	virtual std::vector<Player>& getPlayers() = 0;
    
};

#endif
