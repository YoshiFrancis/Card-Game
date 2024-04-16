#include "Deck.h"
#include "UnoCard.h"
#include "../helper.h"
#include <iostream>
#include <string_view>


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

	return cards;
}

void Deck::addCardToDeck(const ICard* card) {
    m_cards.push_back(card);
    ++m_count;
}

const ICard* Deck::peek() const {
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
	std::vector<const ICard*> cards{};
	if (type == "Uno") {
		srand(time(NULL));
		UnoCard card{};
		auto colors = card.getAllColors();
		auto symbols = card.getAllSymbols();
		auto color_size = colors.size();
		auto symbols_size = symbols.size();
		for (int idx = 0; idx < count; ++idx) {
			std::string color = std::string(colors[Helper::generateRandomNumber(0, color_size)]);
			std::string symbol{};
			if (color == "all") {
				symbol = symbols[Helper::generateRandomNumber(0, 2)]; 
			} else {
				symbol = symbol[Helper::generateRandomNumber(2, symbols_size)];
			}
			std::string name = color + " " + symbol;
			cards.push_back(new UnoCard(name));
		}
	}
	return cards;
}
