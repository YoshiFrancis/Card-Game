#include "Deck.h"
#include "UnoCard.h"
#include "../helper.h"
#include <iostream>
#include <string_view>
#include <random>

constexpr int UNO_DECK_COUNT = 25;
static const ICard* _generateUnoCard();


Deck::~Deck() {
	std::for_each(m_cards.begin(), m_cards.end(), [](const ICard* card) { free( (ICard*) card); });	
}

void Deck::createDeck(const std::string& type) {
	if (type == "Uno") {
		m_cards = Deck::generateDeck(UNO_DECK_COUNT, type);
		m_count = UNO_DECK_COUNT; 
	}
	// do something
	// not needed for implementation, but it is here for now to show that the randomization works
	std::cout << "Before randomization: " << "\n";
	for (auto card : m_cards) {
		std::cout << card->getName() << "\n";
	}
	Deck::randomizeDeck();
	std::cout << "After randomization:\n";
	for (auto card : m_cards) {
		std::cout << card->getName() << "\n";
	}
}

void Deck::randomizeDeck() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(m_cards.begin(), m_cards.end(), g);
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
	std::vector<const ICard*> cards(count);
	if (type == "Uno") {
		std::generate(cards.begin(), cards.end(), _generateUnoCard);
	}
	return cards;
}

static const ICard* _generateUnoCard() {
	UnoCard card{};
	std::vector<std::string>& colors = card.getAllColors();
	std::vector<std::string>& symbols = card.getAllSymbols();
	auto color_size = colors.size();
	auto symbols_size = symbols.size();
	std::string color = colors[Helper::generateRandomNumber(0, color_size-1)];
	std::string symbol{};
	if (color == "all") {
		symbol = symbols[Helper::generateRandomNumber(0, 1)];
	} else {
		symbol = symbols[Helper::generateRandomNumber(2, symbols_size - 1)];
	}
	std::string name = color + " " + symbol;
	return new UnoCard(name);
}

	
