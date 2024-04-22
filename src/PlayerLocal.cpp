#include "PlayerLocal.h"
#include "ICard.h"
#include <string>
#include <memory>
#include <vector>

std::unique_ptr<ICard> PlayerLocal::playCard(const std::string& name) {
	return m_hand.useCard(name);
}
void PlayerLocal::drawCards(std::vector<std::unique_ptr<ICard>> cards) {
	std::for_each(cards.begin(), cards.end(), [&](auto& card) { m_hand.addCard(std::move(card)); });
}

/*
std::shared_ptr<IClient> PlayerLocal::getClient() {
	return m_client;
}
*/

void PlayerLocal::viewCards() {
	m_hand.displayCards();
}

void PlayerLocal::discardHand() {
	m_hand.discardAll();
}

std::string_view PlayerLocal::getUsername() {
	return m_username;
}

int PlayerLocal::getCardCount() {
	return m_hand.getCount();
}
