#ifndef HANDLOCAL_H
#define HANDLOCAL_H

#include "ICard.h"
#include <string>
#include <memory>
#include <iterator>
#include <list>

class Hand {

public:
	std::unique_ptr<ICard> useCard(const std::string& name);
	const void addCard(std::unique_ptr<ICard> card);
	int getCount();
	bool hasCard(const std::string&);
	void discardAll();
	std::string getCards();

private:
	std::list<std::unique_ptr<ICard>> m_cards;
	int m_cardCount { };

	std::list<std::unique_ptr<ICard>>::iterator findCard(const std::string& name);
	void removeCard(const std::string& name);
};


#endif
