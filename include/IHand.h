#ifndef IHAND_H
#define IHAND_H

#include <vector>
#include <string_view>

#include "ICard.h"

class IHand {
public:

    IHand() {}

    virtual std::unique_ptr<ICard> useCard(std::string_view name) = 0;
    virtual const void addCard(std::unique_ptr<ICard> card) = 0;
    virtual const int getCount() = 0;
    virtual const bool hasCard(std::string_view name) = 0;
	virtual void discardAll() = 0;
	virtual void displayCards() = 0;
    virtual ~IHand() {};

};

#endif
