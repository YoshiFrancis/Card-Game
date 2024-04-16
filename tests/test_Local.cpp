#include "UnoCard.h"
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

