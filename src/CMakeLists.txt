add_library(local STATIC HandlerLocal.cpp CardGame.cpp HandLocal.cpp PlayerLocal.cpp UnoCard.cpp Deck.cpp)
target_include_directories(local PUBLIC ${PROJECT_SOURCE_DIR}/include)
