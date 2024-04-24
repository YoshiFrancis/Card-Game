#ifndef IPLAYERCONTAINER_H
#define IPLAYERCONTAINER_H

#include "Player.h"
#include <string_view>
#include <vector>
#include <iterator>

class Player;

class IPlayerContainer {

public:
    virtual ~IPlayerContainer() {}
    virtual bool addPlayer(Player player) = 0;
    virtual bool removePlayer(std::string_view name) = 0;
    virtual std::vector<Player>::iterator findPlayer(std::string_view name) = 0;
	virtual std::vector<Player>& getPlayers() = 0;
    
};

#endif
