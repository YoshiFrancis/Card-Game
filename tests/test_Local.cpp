#include "UnoCard.h"
#include "Hand.h"
#include "Deck.h"
#include "Player.h"
#include "PlayerContainer.h"
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <string_view>
#include <iostream>

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

TEST_CASE( "Hand", "[Hand]" ) {
    Hand hand;

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

/*
TEST_CASE (" Player Creation ", "[Player]" ) {

	Player player {"Yoshi"};
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
	}

	SECTION( " Player can view cards ") {
        std::unique_ptr<ICard> card1 =  std::unique_ptr<ICard>(new UnoCard("blue two"));
        auto card2 =  std::unique_ptr<ICard>(new UnoCard("green one"));
        auto card3 =  std::unique_ptr<ICard>(new UnoCard("all change"));
		std::vector<std::unique_ptr<ICard>> cards {};
		cards.push_back(std::move(card1));
		cards.push_back(std::move(card2));
		cards.push_back(std::move(card3));
		player.drawCards(std::move(cards));
		REQUIRE(player.getCards() == "blue two green one all change ");
	}

	SECTION( "Player able to discard hand " ) {
		auto cards = deck.drawCards(5);
		player.drawCards(std::move(cards));
		REQUIRE(player.getCardCount() == 5);
		player.discardHand();
		REQUIRE(player.getCardCount() == 0);
	}


}

TEST_CASE (" PLayer Container ", "[PlayerContainer]" ) {

	Player player1 {"Yoshi"};
	Player player2 {"Mario"};
	Player player3 {"Luigi"};
	PlayerContainer container{};
	
	SECTION( "PlayerContainer correctly instantiated ") {
		REQUIRE(container.getPlayerCount() == 0);
		REQUIRE(container.getMaxCount() == 8);

	}
	
	SECTION( "PlayerContainer add player" )  {
		container.addPlayer(std::move(player1));
		REQUIRE(container.getPlayerCount() == 1);
		container.addPlayer(std::move(player2));
		REQUIRE(container.getPlayerCount() == 2);
		container.addPlayer(std::move(player3));
		REQUIRE(container.getPlayerCount() == 3);
	}

	SECTION( "PlayerContainer remove player" ) {
		container.addPlayer(std::move(player1));
		container.addPlayer(std::move(player2));
		container.addPlayer(std::move(player3));
		container.removePlayer("Mario");
		REQUIRE(container.getPlayerCount() == 2);
		container.removePlayer("Luigi");
		REQUIRE(container.getPlayerCount() == 1);
		container.removePlayer("Yoshi");
		REQUIRE(container.getPlayerCount() == 0);
		REQUIRE(container.removePlayer("No one") == false);
	}

	SECTION( "PlayerContainer get players" ) {
		container.addPlayer(std::move(player1));
		container.addPlayer(std::move(player2));
		container.addPlayer(std::move(player3));
		auto& players = container.getPlayers();
		REQUIRE(players.size() == 3);
		REQUIRE(players[0].getUsername() == "Yoshi");
		REQUIRE(players[1].getUsername() == "Mario");
		REQUIRE(players[2].getUsername() == "Luigi");
	}
}
*/
