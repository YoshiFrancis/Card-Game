#ifndef IPLAYER_H
#define IPLAYER_H

#include "IClient.h"
#include "ICard.h"
#include <string>
#include <memory>

class IPlayer {
public:
    virtual std::unique_ptr<ICard> playCard(const std::string& name) = 0;
    virtual void drawCard(std::unique_ptr<ICard> card) = 0;
	virtual void viewCards() = 0;
//     virtual std::shared_ptr<IClient> getClient() = 0;
	virtual std::string_view getUsername() = 0; 

    virtual ~IPlayer() {};
    
};

#endif
