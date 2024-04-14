cmake_minimum_required(VERSION 3.29)
project(CardGame
        VERSION 3.29
        LANGUAGES CXX
)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE debug)

add_executable(main main.cpp)
add_subdirectory(src)

target_link_libraries(main PUBLIC local)


# Fetching Catch2 for unit testing
include(FetchContent)
FetchContent_Declare(Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(test_local test_UnoCard.cpp)
target_link_libraries(test_local PUBLIC local Catch2::Catch2WithMain)

add_executable(test_helper test_helper.cpp)
add_library(helper STATIC helper.cpp)
target_link_libraries(test_helper PUBLIC helper Catch2::Catch2WithMain)


enable_testing()

add_test(NAME local_tests COMMAND test_local)
add_test(NAME helper_tests COMMAND test_helper)

