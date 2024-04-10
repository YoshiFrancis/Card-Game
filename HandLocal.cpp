#include "HandLocal.h"


const ICard* HandLocal::useCard(std::string_view name) {
    return findCard(name);
}

const void HandLocal::addCard(const ICard card) {
    ++m_cardCount;
    m_cards.push_back(card);
}

const int HandLocal::getCount() override {
    return m_CardCount;
}

const bool hasCard(std::string_view name) const {
    if (findCard(name) != nullptr)
        return true;
    else 
        return false;
}

ICard* HandLocal::findCard(std::string_view name) {
    for (auto& card : m_cards) {
        if (card.getName() == name) 
            return card;
    return nullptr;
}

void HandLocal::removeCard(std::string_view name) {
    m_cards.erase(findCard(name));
}

