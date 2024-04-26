#include "Player.h"
#include "ICard.h"
#include <string>
#include <string_view>
#include <memory>
#include <vector>

std::unique_ptr<ICard> Player::playCard(const std::string& name) {
	return m_hand->useCard(name);
}
void Player::drawCards(std::vector<std::unique_ptr<ICard>> cards) {
	std::for_each(cards.begin(), cards.end(), [&](auto& card) { m_hand->addCard(std::move(card)); });
}

/*
std::shared_ptr<IClient> Player::getClient() {
	return m_client;
}
*/

std::string_view Player::getCards() {
	return m_hand->getCards();
}

void Player::discardHand() {
	m_hand->discardAll();
}

std::string_view Player::getUsername() {
	return m_username;
}

int Player::getCardCount() {
	return m_hand->getCount();
}
