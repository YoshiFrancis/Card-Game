#ifndef HANDLOCAL_H
#define HANDLOCAL_H

#include "IHand.h"
#include "ICard.h"
#include <string_view>
#include <string>
#include <memory>
#include <iterator>

class Hand : IHand {

public:
	std::unique_ptr<ICard> useCard(std::string_view name) override;
	const void addCard(std::unique_ptr<ICard> card) override;
	const int getCount() override;
	const bool hasCard(std::string_view) override;
	void discardAll() override;
	std::string getCards() override;
	void viewCards();

private:
	std::vector<std::unique_ptr<ICard>> m_cards;
	int m_cardCount { };

	std::vector<std::unique_ptr<ICard>>::iterator findCard(std::string_view name);
	void removeCard(std::string_view name);
};


#endif
