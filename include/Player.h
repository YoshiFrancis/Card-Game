#ifndef PLAYERLOCAL_H
#define PLAYERLOCAL_H

#include "IPlayer.h"
#include "ICard.h"
#include "Hand.h"
#include "message.hpp"
#include <string_view>
#include <string>
#include <memory>
#include <vector>
#include <iostream>

class Player : public IPlayer {
public:

	Player(conn_ptr conn, std::string username="Guest") : m_conn { conn }, m_username { username }
	{
		std::cout << m_username << " player has been created!\n";
	}

	~Player() = default;

	Player(const Player& other) = delete;

	Player(Player&& other) noexcept
	{
		m_conn = other.m_conn;
		m_username = other.m_username;
		m_hand = std::move(other.m_hand);
	}

	Player& operator=(const Player& other) = delete;

	Player& operator=(Player&& other) noexcept
	{
		m_username = other.m_username;
		m_hand = std::move(other.m_hand);
		m_conn = other.m_conn;
		return *this;
	}

	std::unique_ptr<ICard> playCard(const std::string& name) override;
	void drawCards(std::vector<std::unique_ptr<ICard>> cards) override; 
	void drawCards(std::unique_ptr<ICard> card) override;
	conn_ptr getConn() override;
	std::string getCards() override;
	std::string getUsername() override;
	void discardHand() override;
	int getCardCount() override;
 
private:
	conn_ptr m_conn;
	Hand m_hand;
	std::string m_username;

};

#endif
