#ifndef HANDLOCAL_H
#define HANDLOCAL_H

#include "IHand.h"
#include <string_view>
#include <memory>

class HandLocal : IHand {

public:
    std::unique_ptr<ICard> useCard(std::string_view name) override;
    const void addCard(std::unique_ptr<ICard> card) override;
    const int getCount() override;
    const bool hasCard(std::string_view) const override;
	void discardAll() override;

private:
    std::vector<std::unique_ptr<ICard>> m_cards;
    int m_cardCount { };

    std::unique_ptr<ICard> findCard(std::string_view name) const;
    void removeCard(std::string_view name);
    

};


#endif
