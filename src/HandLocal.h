#ifndef HANDLOCAL_H
#define HANDLOCAL_H

#include "IHand.h"
#include <string_view>

class HandLocal : IHand {

public:
    const ICard* useCard(std::string_view name) override;
    const void addCard(const ICard* card) override;
    const int getCount() override;
    const bool hasCard(std::string_view) const override;

private:
    std::vector<const ICard*> m_cards;
    int m_cardCount { };

    const ICard* findCard(std::string_view name) const;
    void removeCard(std::string_view name);
    

};


#endif
