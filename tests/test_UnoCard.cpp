#include <catch2/catch_test_macros.hpp>

TEST_CASE( "Runs", "[UnoCard]" ) {
    SECTION ("Checking if it succeeds") {
        CHECK(1 + 1 == 2);
    }
}

TEST_CASE( "Fails", "[UNOCARD]" ) {
    SECTION("CHECKING IF IT FAILS") {
        CHECK( 1 + 1 == 3);
    }
}
