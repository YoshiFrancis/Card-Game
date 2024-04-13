cmake_minimum_required(VERSION 3.29)
project(test_local_sources)

# Fetching Catch2 for unit testing
include(FetchContent)
FetchContent_Declare(Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.3.2
)
FetchContent_MakeAvailable(Catch2)

add_executable(test_local test_UnoCard.cpp)
target_include_directories( test_local PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(test_local PRIVATE Catch2::Catch2)

