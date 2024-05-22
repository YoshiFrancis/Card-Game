#ifndef IPLAYERCONTAINER_H
#define IPLAYERCONTAINER_H

#include "Player.h"
#include <string>
#include <list>
#include <iterator>

class Player;

typedef std::list<Player>::iterator player_iter;

class IPlayerContainer {

public:
	virtual ~IPlayerContainer() {}
	virtual bool addPlayer(Player player) = 0;
	virtual void removePlayer(std::string name) = 0;
	virtual player_iter findPlayer(std::string name) = 0;
    
};

#endif
