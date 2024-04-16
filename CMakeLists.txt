cmake_minimum_required(VERSION 3.29)
project(CardGame
        VERSION 3.29
        LANGUAGES CXX
)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE debug)

message(${CMAKE_CURRENT_SOURCE_DIR}/helper.cpp)

add_library(helper STATIC ${CMAKE_CURRENT_SOURCE_DIR}/helper.cpp)
target_include_directories(helper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/helper.h)

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(local PUBLIC helper)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC local)

# Fetching Catch2 for unit testing
include(FetchContent)
FetchContent_Declare(Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

target_link_libraries(test_local PUBLIC local)
target_link_libraries(test_helper PUBLIC helper)


enable_testing()

add_test(NAME local_tests COMMAND test_local)
add_test(NAME helper_tests COMMAND test_helper)

