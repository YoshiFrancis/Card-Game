#include "Hand.h"
#include "ICard.h"
#include <algorithm>
#include <memory>
#include <iterator>


std::unique_ptr<ICard> Hand::useCard(const std::string& name) {
   	auto cardIt = findCard(name);
		if (cardIt == m_cards.end()) {
			return nullptr;
		}
		auto card = std::move(*cardIt);
		m_cards.erase(cardIt);
		--m_cardCount;
    return std::move(card);
}

const void Hand::addCard(std::unique_ptr<ICard> card) {
    ++m_cardCount;
    m_cards.push_back(std::move(card));
}

int Hand::getCount() {
    return m_cardCount;
}

bool Hand::hasCard(const std::string& name) {
    if (findCard(name) != m_cards.end())
        return true;
    else 
        return false;
}

std::list<std::unique_ptr<ICard>>::iterator Hand::findCard(const std::string& name) {
	auto it = std::find_if(m_cards.begin(), m_cards.end(), [&](auto& card) { return card->getName() == name; } );
	return it;
}

void Hand::removeCard(const std::string& name) {
    auto it = std::find_if(m_cards.begin(), m_cards.end(), [&](auto& card) { return card->getName() == name; } );
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
