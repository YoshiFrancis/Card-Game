#include "HandLocal.h"


const ICard* HandLocal::useCard(std::string_view name) {
    return findCard(name);
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
    for (const auto* card : m_cards) {
        if (card->getName() == name) 
            return card;
    }
    return nullptr;
}

void HandLocal::removeCard(std::string_view name) {
    // need to implement findCard with find_if
}

