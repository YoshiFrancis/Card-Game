#ifndef ICARD_H
#define ICARD_H

#include <string_view>

class ICard {

    virtual std::string_view getType() = 0;
    virtual ~ICard();
    
};

#endif