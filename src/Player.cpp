#include "Player.h"
#include "ICard.h"
#include "message.hpp"
#include <string>
#include <string_view>
#include <memory>
#include <vector>

std::unique_ptr<ICard> Player::playCard(const std::string& name) {
	std::cout << "in player::playcard\n";
	return m_hand.useCard(name);
}
void Player::drawCards(std::vector<std::unique_ptr<ICard>> cards) {
	std::for_each(cards.begin(), cards.end(), [&](auto& card) { m_hand.addCard(std::move(card)); });
}

void Player::drawCards(std::unique_ptr<ICard> card) {
	m_hand.addCard(std::move(card));
}

conn_ptr Player::getConn() {
	return m_conn;
}

std::string Player::getCards() {
	return std::move(m_hand.getCards());
}

void Player::discardHand() {
	m_hand.discardAll();
}

std::string Player::getUsername() {
	return m_username;
}

int Player::getCardCount() {
	return m_hand.getCount();
}
