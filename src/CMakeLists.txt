add_library(local STATIC HandLocal.cpp Player.cpp UnoCard.cpp Deck.cpp)
target_include_directories(local PUBLIC ${PROJECT_SOURCE_DIR}/include)
