cmake_minimum_required(VERSION 3.29)
project(CardGame
        VERSION 3.29
        LANGUAGES CXX
)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE debug)

#add_library(blah STATIC src/HandlerLocal.cpp)
#target_include_directories(blah PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(main main.cpp)
add_subdirectory(src)
#add_subdirectory(tests)

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



enable_testing()

add_test(NAME local_tests COMMAND test_local)

