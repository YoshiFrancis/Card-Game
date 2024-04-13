#ifndef IHAND_H
#define IHAND_H

#include <vector>
#include <string_view>

#include "ICard.h"

class IHand {
public:

    IHand(std::vector<ICard*> cards) {
    // do something
    }

    virtual const ICard* useCard(std::string_view name) = 0;
    virtual const void addCard(const ICard* card) = 0;
    virtual const int getCount() = 0;
    virtual const bool hasCard(std::string_view name) const = 0;
    virtual ~IHand() {};

};

#endif
