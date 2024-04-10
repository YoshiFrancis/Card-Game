cmake_minimum_required(VERSION 3.29)
project(CardGame
        VERSION 3.29
        LANGUAGES CXX
)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE debug)

add_executable(game 
    main.cpp
    HandlerLocal.cpp
    PlayerLocal.cpp
    HandLocal.cpp
    CardGame.cpp
)

target_include_directories(game PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

