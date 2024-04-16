#include "UnoCard.h"
#include "HandLocal.h"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <string_view>

TEST_CASE( "Can be default constructured", "[UnoCard]" ) {
    UnoCard card { "RED ONE" };

    SECTION( " able to properly get name ") {
        std::string name = card.getName();
        REQUIRE( name == "red one" );
    }

    SECTION( " get type " ) {
        std::string_view type = card.getType();
        REQUIRE( type == "Uno" );
    }
     

}

TEST_CASE( "Hand Local", "[HandLocal]" ) {
    

    HandLocal hand;

    SECTION( " able to add card " ) {
        UnoCard* card = new UnoCard("blue two");
        hand.addCard(card);
        REQUIRE(hand.getCount() == 1);
        REQUIRE(hand.hasCard("blue two") == true);

        delete card;
    }

    SECTION( " able to use card ") {
        UnoCard* card = new UnoCard("green four");
        hand.addCard(card);
        const ICard* newCard = hand.useCard("green four");
        REQUIRE(hand.getCount() == 0);
        REQUIRE(newCard->getName() == "green four");
        delete card;
    }
}
