#include "UnoCard.h"
#include <iostream>
int main(int argc, char* argv[]) {
    UnoCard card {"red one"};
    std::cout << card.getName() << "\n";
    return 1;
}
