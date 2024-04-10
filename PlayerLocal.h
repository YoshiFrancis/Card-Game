#ifndef PLAYERLOCAL_H
#define PLAYERLOCAL_H

#include "HandLocal.h"
#include "ClientLocal.h"
#include <string_view>

class IClient;
class IHand;
class ICard;

class PlayerLocal {
public:

    PlayerLocal(IClient* client, std::vector<ICard>, m_hand, std::string_view username) : m_client {client}, m_hand {cards}, m_username { username }
    {}

    ICard playCard() override;
    void drawCard(ICard card) override; 
    const IClient* getClient() override;
    const IHand* getHand() const;
    void discardHand();
 

private:
    IClient* m_client;
    IHand m_hand;
    std::string_view m_username;
  
};

#endif
