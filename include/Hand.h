#ifndef HANDLOCAL_H
#define HANDLOCAL_H

#include "IHand.h"
#include "ICard.h"
#include <string>
#include <memory>
#include <iterator>

class Hand : IHand {

public:
	std::unique_ptr<ICard> useCard(const std::string& name) override;
	const void addCard(std::unique_ptr<ICard> card) override;
	const int getCount() override;
	const bool hasCard(const std::string&) override;
	void discardAll() override;
	std::string getCards() override;
	void viewCards();

private:
	std::vector<std::unique_ptr<ICard>> m_cards;
	int m_cardCount { };

	std::vector<std::unique_ptr<ICard>>::iterator findCard(const std::string& name);
	void removeCard(const std::string& name);
};


#endif
