#include "UnoCard.h"
#include "HandLocal.h"
#include "Deck.h"
#include "PlayerLocal.h"
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
        auto card =  std::unique_ptr<ICard>(new UnoCard("blue two"));
        hand.addCard(std::move(card));
        REQUIRE(hand.getCount() == 1);
        REQUIRE(hand.hasCard("blue two") == true);

    }

    SECTION( " able to use card ") {
        auto card = std::unique_ptr<ICard>(new UnoCard("green four"));
        hand.addCard(std::move(card));
        std::unique_ptr<ICard> newCard = hand.useCard("green four");
        REQUIRE(hand.getCount() == 0);
    //    REQUIRE(newCard->getName() == "green four");
    }


}

TEST_CASE ("Deck creation" , "[Deck]" ) {

	Deck deck;
	int deckCount = 25;

	SECTION (" add card ") {
		auto card1 = std::unique_ptr<ICard>(new UnoCard{ "red one" });
		auto card2 = std::unique_ptr<ICard>(new UnoCard{ "blue two" });
		auto card3 = std::unique_ptr<ICard>(new UnoCard{ "green four" });
		deck.addCardToDeck(std::move(card1));
		REQUIRE(deck.getCount() == deckCount + 1);
		deck.addCardToDeck(std::move(card2));
		REQUIRE(deck.getCount() == deckCount + 2);
		deck.addCardToDeck(std::move(card3));
		REQUIRE(deck.getCount() == deckCount + 3);
		
		REQUIRE(deck.peek() != "");
	}

	SECTION (" drawing cards ") {
		auto card1 = std::unique_ptr<ICard>(new UnoCard{ "red one" });
		auto card2 = std::unique_ptr<ICard>(new UnoCard{ "blue two" });
		auto card3 = std::unique_ptr<ICard>(new UnoCard{ "green four" });
		deck.addCardToDeck(std::move(card1));
		deck.addCardToDeck(std::move(card2));
		deck.addCardToDeck(std::move(card3));
		deck.drawCards(deckCount);
		auto cards1 = deck.drawCards(1);
		REQUIRE(cards1[0]->getName() == "red one");
		auto cards2 = deck.drawCards(2);
		REQUIRE(cards2[0]->getName() == "blue two");
		REQUIRE(cards2[1]->getName() == "green four");
		REQUIRE(deck.getCount() == 0);
	}


	SECTION( " stated amount of cards: Uno" ) {
		Deck deck{"Uno"};
		REQUIRE(deck.getCount() == deckCount);
		int count = deck.getCount();
	}

}

TEST_CASE (" Player Creation ", "[Player]" ) {

	PlayerLocal player {"Yoshi"};
	Deck deck;

	SECTION( " correctly instantiated " ) {
		REQUIRE(player.getUsername() == "Yoshi");
		REQUIRE(player.getCardCount() == 0);
	}

	SECTION( " Player able to draw " ) {
		auto card = deck.drawCards(1);
		player.drawCards(std::move(card));
		REQUIRE(player.getCardCount() == 1);
		auto cards = deck.drawCards(5);
		player.drawCards(std::move(cards));
		REQUIRE(player.getCardCount() == 6);
		player.viewCards();
	}

	SECTION( "Player able to discard hand " ) {
		auto cards = deck.drawCards(5);
		player.drawCards(std::move(cards));
		REQUIRE(player.getCardCount() == 5);
		player.discardHand();
		REQUIRE(player.getCardCount() == 0);
	}


}

