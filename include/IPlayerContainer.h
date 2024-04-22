#ifndef IPLAYERCONTAINER_H
#define IPLAYERCONTAINER_H

#include <string_view>
#include <vector>
#include <iterator>

class IPlayer;

class IPlayerContainer {

public:
    virtual ~IPlayerContainer();
    virtual void addPlayer(IPlayer player) = 0;
    virtual void removePlayer(std::string_view name) = 0;
    virtual std::vector<IPlayer>::iterator findPlayer() = 0;
    
};

#endif
