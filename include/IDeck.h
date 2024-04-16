#ifndef IDECK_H
#define IDECK_H


#include <vector>

class ICard;

class IDeck {

public:
    virtual std::vector<const ICard*> drawCards(int count) = 0;
    virtual void createDeck() = 0;
    virtual void randomizeDeck() = 0;
    virtual void addCardToDeck(const ICard* card) = 0;
    virtual ~IDeck() {}


    
};

#endif
