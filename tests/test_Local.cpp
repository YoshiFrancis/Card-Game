#include "UnoCard.h"
#include "HandLocal.h"
#include "Deck.h"
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



TEST_CASE ("Deck creation" , "[Deck]" ) {

	Deck deck;

	SECTION (" add card ") {
		UnoCard* card1 = new UnoCard{ "red one" };
		UnoCard* card2 = new UnoCard{ "blue two" };
		UnoCard* card3 = new UnoCard{ "green four" };
		deck.addCardToDeck(card1);
		REQUIRE(deck.getCount() == 6);
		deck.addCardToDeck(card2);
		REQUIRE(deck.getCount() == 7);
		deck.addCardToDeck(card3);
		REQUIRE(deck.getCount() == 8);
		
		REQUIRE(deck.peek()->getType() == "Uno");
	}

	SECTION (" drawing cards ") {
		UnoCard* card1 = new UnoCard{ "red one" };
		UnoCard* card2 = new UnoCard{ "blue two" };
		UnoCard* card3 = new UnoCard{ "green four" };
		deck.addCardToDeck(card1);
		deck.addCardToDeck(card2);
		deck.addCardToDeck(card3);
		deck.drawCards(5);
		auto cards1 = deck.drawCards(1);
		REQUIRE(cards1[0]->getName() == "red one");
		auto cards2 = deck.drawCards(2);
		REQUIRE(cards2[0]->getName() == "blue two");
		REQUIRE(cards2[1]->getName() == "green four");
		REQUIRE(deck.getCount() == 0);
	}


	SECTION( " stated amount of cards: Uno" ) {
		Deck deck{"Uno"};
		REQUIRE(deck.getCount() == 5);
		int count = deck.getCount();
	}
}
