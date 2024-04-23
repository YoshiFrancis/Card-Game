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

class Player : public IPlayer {
public:

    Player(std::string_view username="Guest") : m_username { username }
    {
	}

    std::unique_ptr<ICard> playCard(const std::string& name) override;
    void drawCards(std::vector<std::unique_ptr<ICard>> cards) override; 
    //std::shared_ptr<IClient> getClient() override;
	void viewCards() override;
	std::string_view getUsername() override;
    void discardHand();
	int getCardCount();
 
    ~Player() override { }

private:
    // std::shared_ptr<IClient> m_client;
    HandLocal m_hand;
    std::string_view m_username;
  
};

#endif
