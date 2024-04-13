#ifndef ICARD_H
#define ICARD_H

#include <string_view>

class ICard {

public:
    virtual std::string_view getType() const = 0;
    virtual std::string_view getName() const = 0;
    virtual ~ICard();
    
};

#endif