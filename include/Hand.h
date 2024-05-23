#ifndef HANDLOCAL_H
#define HANDLOCAL_H

#include "IHand.h"
#include "ICard.h"
#include <string>
#include <memory>
#include <iterator>
#include <list>

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
	std::list<std::unique_ptr<ICard>> m_cards;
	int m_cardCount { };

	std::list<std::unique_ptr<ICard>>::iterator findCard(const std::string& name);
	void removeCard(const std::string& name);
};


#endif
