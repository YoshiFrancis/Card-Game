#include "HandLocal.h"
#include "ICard.h"
#include <algorithm>
#include <memory>
#include <iterator>
#include <iostream>


std::unique_ptr<ICard> HandLocal::useCard(std::string_view name) {
   	auto card = findCard(name);
    removeCard(name);
    return std::move(*card);
}

const void HandLocal::addCard(std::unique_ptr<ICard> card) {
    ++m_cardCount;
    m_cards.push_back(std::move(card));
}

const int HandLocal::getCount() {
    return m_cardCount;
}

const bool HandLocal::hasCard(std::string_view name) {
    if (findCard(name) != m_cards.end())
        return true;
    else 
        return false;
}

std::vector<std::unique_ptr<ICard>>::iterator HandLocal::findCard(std::string_view name) {
    auto it = std::find_if(m_cards.begin(), m_cards.end(), [&](auto& card) { return (*card).getName() == name; } );
	return it;
}

void HandLocal::removeCard(std::string_view name) {
    auto it = std::find_if(m_cards.begin(), m_cards.end(), [&](auto& card) { return (*card).getName() == name; } );
    m_cards.erase(it);
    --m_cardCount;
}

void HandLocal::discardAll() {
	m_cards.clear();
}

void HandLocal::displayCards() {
	std::for_each(m_cards.begin(), m_cards.end(), [&](auto& card) { std::cout << card->getName(); });
}
