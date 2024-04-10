#ifndef PLAYERLOCAL_H
#define PLAYERLOCAL_H

#include "IPlayer.h"
#include "ICard.h"
#include "IHand.h"
#include <string_view>
#include <memory>

class IClient;
class IHand;

class PlayerLocal : public IPlayer {
public:

    PlayerLocal(IClient* client, std::string_view username) : m_client {client}, m_username { username }
    {}

    ICard playCard() override;
    void drawCard(ICard card) override; 
    const IClient* getClient() override;
    const IHand* getHand() const;
    void discardHand();
 

private:
    IClient* m_client;
    IHand* m_hand;
    std::string_view m_username;
  
};

#endif
