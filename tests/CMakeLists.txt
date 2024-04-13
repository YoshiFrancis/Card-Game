# Fetching Catch2 for unit testing
include(FetchContent)
FetchContent_Declare(Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(test_local test_UnoCard.cpp test_testing.cpp)
target_include_directories(test_local PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(test_local PRIVATE Catch2::Catch2WithMain)

