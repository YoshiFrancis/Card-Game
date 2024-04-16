cmake_minimum_required(VERSION 3.29)

# Fetching Catch2 for unit testing
include(FetchContent)
FetchContent_Declare(Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(test_local test_Local.cpp)
target_link_libraries(test_local PRIVATE Catch2::Catch2WithMain)

add_executable(test_helper test_helper.cpp)
target_link_libraries(test_helper PRIVATE Catch2::Catch2WithMain)
