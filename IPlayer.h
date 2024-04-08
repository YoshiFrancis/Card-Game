#ifndef IPLAYER_H
#define IPLAYER_H

class ICard;

class IPlayer {

    virtual ~IPlayer();
    virtual ICard playCard() = 0;
    virtual void drawCard(ICard card) = 0;
    
};

#endif