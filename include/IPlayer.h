#ifndef IPLAYER_H
#define IPLAYER_H

#include <string>

class ICard;
class IClient;

class IPlayer {
public:
    virtual ICard playCard(const std::string& name) = 0;
    virtual void drawCard(ICard card) = 0;
    virtual const IClient* getClient() = 0;

    virtual ~IPlayer() {};
    
};

#endif
