cmake_minimum_required(VERSION 3.29)
project(CardGame
        VERSION 3.29
        LANGUAGES CXX
)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE debug)

add_executable(main 
    main.cpp
    src/HandlerLocal.cpp
    src/HandLocal.cpp
    src/PlayerLocal.cpp
)

target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/include)


include(CTest)
add_executable(UnoCardTest tests/test_UnoCard.cpp)
target_link_libraries(UnoCardTest 

