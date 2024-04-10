#ifndef IPLAYERCONTAINER_H
#define IPLAYERCONTAINER_H

#include <string_view>
#include <vector>

class IPlayer;

class IPlayerContainer {

    virtual ~IPlayerContainer();
    virtual void addPlayer(IPlayer player) = 0;
    virtual void removePlayer(std::string_view name) = 0;
    virtual std::vector<IPlayer*> getPlayers() = 0;
    virtual void orderPlayers() = 0;
    
};

#endif