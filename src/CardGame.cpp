#include "CardGame.h"

#include <iostream>

void CardGame::startGame() {
    waitForPlayers();
    std::cout << "Now beginning the game...";
}

void CardGame::waitForPlayers() {
    /*
    while m_communicating is waiting for players
        add new player
        announce to all current players the new player
    */
}
