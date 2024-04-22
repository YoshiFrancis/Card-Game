#ifndef IDECK_H
#define IDECK_H


#include <vector>
#include <string>
#include <memory>

class ICard;

class IDeck {

public:
    virtual std::vector<std::unique_ptr<ICard>> drawCards(int count) = 0;
    virtual void createDeck(const std::string& type) = 0;
    virtual void randomizeDeck() = 0;
    virtual void addCardToDeck(std::unique_ptr<ICard> card) = 0;
    virtual ~IDeck() {}


    
};

#endif
