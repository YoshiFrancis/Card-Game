#ifndef IPLAYER_H
#define IPLAYER_H

class ICard;
class IClient;

class IPlayer {

    virtual ~IPlayer();
    virtual ICard playCard() = 0;
    virtual void drawCard(ICard card) = 0;
    virtual const IClient* getClient() = 0;
    
};

#endif
