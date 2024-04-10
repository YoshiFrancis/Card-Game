#ifndef HANDLOCAL_H
#define HANDLOCAL_H

#include "IHand.h"

class HandLocal : IHand {

public:
    const ICard* useCard(std::string_view name) override;
    const void addCard(const ICard card) override;
    const int getCount() override;
    const bool hasCard() const override;

private:
    std::vector<const ICard> m_cards;
    int m_cardCount { 0 };

    const ICard* findCard(std::string_view name);
    const bool removeCard(std::string_view name);
    

};


#endif
