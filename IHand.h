#ifndef IHAND_H
#define IHAND_H

#include <vector>
#include <string_view>

class ICard;

class IHand {

    virtual const ICard useCard(std::string_view name) = 0;
    virtual const void addCard(const ICard card) = 0;
    virtual const int getCount() = 0;
    virtual const bool hasCard() const = 0;
    virtual ~Hand();

};

#endif
