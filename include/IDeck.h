#ifndef IDECK_H
#define IDECK_H


#include <string_view>

class ICard;

class IDeck {

    virtual ICard drawCards(int count) = 0;
    virtual void createDeck() = 0;
    virtual void randomizeDeck() = 0;
    virtual void addCard(ICard&& card) = 0;
    virtual ~IDeck();


    
};

#endif
