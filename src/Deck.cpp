#include "Deck.h"
#include "UnoCard.h"
#include "../helper.h"
#include <iostream>
#include <string_view>
#include <random>

#define SHOW_RANDOMIZATION 0

constexpr int UNO_DECK_COUNT = 10;
static std::unique_ptr<ICard> _generateUnoCard();


Deck::~Deck() {
	std::cout << "Destroying deck\n";
}

void Deck::createDeck(const std::string& type) {
	if (type == "Uno") {
		m_cards = Deck::generateDeck(UNO_DECK_COUNT, type);
		m_count = UNO_DECK_COUNT; 
	}
	// do something
	// not needed for implementation, but it is here for now to show that the randomization works
	#if SHOW_RANDOMIZATION
	std::cout << "Before randomization: " << "\n";
	for (const auto& card : m_cards) {
		std::cout << card->getName() << "\n";
	}
	#endif
	Deck::randomizeDeck();
	#if SHOW_RANDOMIZATION
	std::cout << "After randomization:\n";
	for (const auto& card : m_cards) {
		std::cout << card->getName() << "\n";
	}
	#endif
}

void Deck::randomizeDeck() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(m_cards.begin(), m_cards.end(), g);
}

std::vector<std::unique_ptr<ICard>> Deck::drawCards(int count) {
    
	std::vector<std::unique_ptr<ICard>> cards{};
	if (count > m_count) {
		count -= m_count;
		cards = drawCards(m_count);
		m_cards = generateDeck(UNO_DECK_COUNT, "Uno");
		m_count = UNO_DECK_COUNT;
	}

	for (int idx {0}; idx < count; ++idx) 
		cards.push_back(std::move(m_cards[idx]));

	m_cards.erase(m_cards.begin(), m_cards.begin() + count);
	m_count -= count;

	return cards;
}

void Deck::addCardToDeck(std::unique_ptr<ICard> card) {
    m_cards.push_back(std::move(card));
    ++m_count;
}

std::string Deck::peek() const {
   if (m_count == 0) 
        return "No card";
   else 
        return m_cards[0]->getName();
}

bool Deck::isEmpty() const {
	if (m_count == 0) return true;
	else return true;
}

int Deck::getCount() const {
	return m_count;
}

std::vector<std::unique_ptr<ICard>> Deck::generateDeck(int count, const std::string type) const {
	std::vector<std::unique_ptr<ICard>> cards(count);
	if (type == "Uno") {
		std::generate(cards.begin(), cards.end(), _generateUnoCard);
	}
	return cards;
}

static std::unique_ptr<ICard>  _generateUnoCard() {
	UnoCard card{};
	const std::vector<std::string>& colors = card.getAllColors();
	const std::vector<std::string>& symbols = card.getAllSymbols();
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
	return std::unique_ptr<ICard>(new UnoCard(name));
}

	
