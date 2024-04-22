#include "HandLocal.h"
#include "ICard.h"
#include <algorithm>
#include <memory>
#include <iostream>


std::unique_ptr<ICard> HandLocal::useCard(std::string_view name) {
   	auto card = findCard(name);
    removeCard(name);
    return card;
}

const void HandLocal::addCard(std::unique_ptr<ICard> card) {
    ++m_cardCount;
    m_cards.push_back(std::move(card));
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

std::unique_ptr<ICard> HandLocal::findCard(std::string_view name) const {
    auto it = std::find_if(m_cards.begin(), m_cards.end(), [&](const auto& card) { return card->getName() == name; } );
	return nullptr;
	/*
    if (it == m_cards.end()) 
        return nullptr;
    else
        return std::move(*it);
	*/
}

void HandLocal::removeCard(std::string_view name) {
    auto it = std::find_if(m_cards.begin(), m_cards.end(), [&](const auto& card) { return card->getName() == name; } );
    m_cards.erase(it);
    --m_cardCount;
}

void HandLocal::discardAll() {
	m_cards.clear();
}

void HandLocal::displayCards() {
	std::for_each(m_cards.begin(), m_cards.end(), [&](const auto& card) { std::cout << card->getName(); });
}
