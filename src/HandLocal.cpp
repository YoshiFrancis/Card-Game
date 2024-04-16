#include "HandLocal.h"


const ICard* HandLocal::useCard(std::string_view name) {
    const ICard* card = findCard(name);
    removeCard(name);
    return card;
}

const void HandLocal::addCard(const ICard* card) {
    ++m_cardCount;
    m_cards.push_back(card);
}

const int HandLocal::getCount() {
    return m_cardCount;
}

const bool HandLocal::hasCard(std::string_view name) const {
    if (findCard(name) != nullptr)
        return true;
    else 
        return false;
}

const ICard* HandLocal::findCard(std::string_view name) const {
    auto it = std::find_if(m_cards.begin(), m_cards.begin(), [&](const ICard* card) { return card->getName() == name; } );
    if (it == m_cards.end()) 
        return nullptr;
    else
        return *it;
}

void HandLocal::removeCard(std::string_view name) {
    auto it = std::find_if(m_cards.begin(), m_cards.begin(), [&](const ICard* card) { return card->getName() == name; } );
    m_cards.erase(it);
    --m_cardCount;
}

