#ifndef IPLAYER_H
#define IPLAYER_H

#include "IClient.h"
#include "ICard.h"
#include <string>
#include <string_view>
#include <memory>
#include <vector>

class IPlayer {
public:
    virtual std::unique_ptr<ICard> playCard(const std::string& name) = 0;
    virtual void drawCards(std::vector<std::unique_ptr<ICard>> cards) = 0;
	virtual std::string getCards() = 0;
//     virtual std::shared_ptr<IClient> getClient() = 0;
	virtual std::string_view getUsername() = 0; 

    virtual ~IPlayer() {};
    
};

#endif
