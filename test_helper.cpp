#include <catch2/catch_test_macros.hpp>
#include "helper.cpp"


TEST_CASE (" to lower function ", "[toLower]" ) {
    
    CHECK( Helper::toLower("HELLO WORLD") == "hello world" );
    CHECK( Helper::toLower("yOsHi is ThE KiNg") == "yoshi is the king" );

}
