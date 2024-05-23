#ifndef ICARD_H
#define ICARD_H

#include <string>

class ICard {

public:
    virtual std::string getType() const = 0;
    virtual std::string getName() const = 0;
    virtual ~ICard(){}
};

#endif
