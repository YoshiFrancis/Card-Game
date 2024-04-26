#ifndef PLAYERLOCAL_H
#define PLAYERLOCAL_H

#include "IPlayer.h"
#include "ICard.h"
#include "HandLocal.h"
// #include "IClient.h"
#include <string_view>
#include <string>
#include <memory>
#include <vector>
#include <iostream>

class Player : public IPlayer {
public:

    Player(std::string_view username="Guest") : m_username { username }, m_hand { std::make_unique<HandLocal>() }
    {
	}

	~Player() = default;

	Player(const Player& other) = delete;

	Player(Player&& other) noexcept
	{
		m_username = other.m_username;
		m_hand = std::move(other.m_hand);
	}

	Player& operator=(const Player& other) = delete;

	Player& operator=(Player&& other) noexcept
	{
		m_username = other.m_username;
		m_hand = std::move(other.m_hand);
		return *this;
	}

    std::unique_ptr<ICard> playCard(const std::string& name) override;
    void drawCards(std::vector<std::unique_ptr<ICard>> cards) override; 
    //std::shared_ptr<IClient> getClient() override;
	std::string_view getCards() override;
	std::string_view getUsername() override;
    void discardHand();
	int getCardCount();
 
private:
    // std::shared_ptr<IClient> m_client;
    std::unique_ptr<HandLocal> m_hand {};
    std::string_view m_username {};
  
};

#endif
