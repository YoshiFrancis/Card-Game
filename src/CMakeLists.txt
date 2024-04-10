cmake_minimum_required(VERSION 3.10)
project(CardGame)
add_executable(Cardgame main.cpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
target_link_directories(CardGame PRIVATE ${CMAKE_SOURCE_DIR})

