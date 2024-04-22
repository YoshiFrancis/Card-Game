#include "PlayerLocal.h"
#include <string>
#include <memory>

class ICard;

std::unique_ptr<ICard> PlayerLocal::playCard(const std::string& name) {
	return m_hand->useCard(name);
}
void PlayerLocal::drawCard(std::unique_ptr<ICard> card) {
	m_hand->addCard(std::move(card));
}

std::shared_ptr<IClient> PlayerLocal::getClient() {
	return m_client;
}

void PlayerLocal::viewCards() {
	m_hand->displayCards();
}

void PlayerLocal::discardHand() {
	m_hand->discardAll();
}

const std::string& getUsername() {
	return m_username;
}
