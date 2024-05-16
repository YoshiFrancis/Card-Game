add_library(helper STATIC ${PROJECT_SOURCE_DIR}/Card-Game/helper.cpp)
target_include_directories(helper PUBLIC ${PROJECT_SOURCE_DIR}/Card-Game/helper.h)

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(unogame PUBLIC helper)


# Fetching Catch2 for unit testing
include(FetchContent)
FetchContent_Declare(Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

target_link_libraries(test_local PUBLIC unogame)
target_link_libraries(test_helper PUBLIC helper)


enable_testing()

add_test(NAME local_tests COMMAND test_local)
add_test(NAME helper_tests COMMAND test_helper)

