#include "Hand.h"
#include "ICard.h"
#include <algorithm>
#include <memory>
#include <iterator>
#include <iostream>


std::unique_ptr<ICard> Hand::useCard(std::string_view name) {
   	auto card = findCard(name);
    removeCard(name);
    return std::move(*card);
}

const void Hand::addCard(std::unique_ptr<ICard> card) {
    ++m_cardCount;
    m_cards.push_back(std::move(card));
}

const int Hand::getCount() {
    return m_cardCount;
}

const bool Hand::hasCard(std::string_view name) {
    if (findCard(name) != m_cards.end())
        return true;
    else 
        return false;
}

std::vector<std::unique_ptr<ICard>>::iterator Hand::findCard(std::string_view name) {
    auto it = std::find_if(m_cards.begin(), m_cards.end(), [&](auto& card) { return (*card).getName() == name; } );
	return it;
}

void Hand::removeCard(std::string_view name) {
    auto it = std::find_if(m_cards.begin(), m_cards.end(), [&](auto& card) { return (*card).getName() == name; } );
    m_cards.erase(it);
    --m_cardCount;
}

void Hand::discardAll() {
	m_cards.clear();
	m_cardCount = m_cards.size();
}

std::string Hand::getCards() {
	std::string cards {};
	std::for_each(m_cards.begin(), m_cards.end(), [&](auto& card) { cards += card->getName() + " "; });
	return std::move(cards);
}

void Hand::viewCards() {
	std::for_each(m_cards.begin(), m_cards.end(), [](auto& card) { std:: cout << card->getName() << "\n"; });
}
