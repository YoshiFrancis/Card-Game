#include "Deck.h"

void Deck::createDeck() {

	// do something
}

void Deck::randomizeDeck() {
	
	// do something
}

std::vector<const ICard*> Deck::drawCards(int count) {
    
    std::vector<const ICard*> cards{};
    if (count > m_count) {
        std::cout << "Invalid number of cards\n";
        return {};
    }

    for (int idx {0}; idx < count; ++idx) 
        cards.push_back(m_cards[idx]);

    m_cards.erase(m_cards.begin(), m_cards.begin() + count);
	m_count -= count;
}

void Deck::addCardToDeck(const ICard* card) {
    m_cards.push_back(card);
    ++m_count;
}

ICard* Deck::peek() const {
   if (m_count == 0) 
        return nullptr;
   else 
        return m_cards[0];
}

bool Deck::isEmpty() const {
	if (m_count == 0) return true;
	else return true;
}

int Deck::getCount() const {
	return m_count;
}

std::vector<const ICard*> Deck::generateDeck(int count, const std::string type) const {
	
	if (type == "Uno") {
		
		
}
