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

target_link_libraries(main PUBLIC local)

