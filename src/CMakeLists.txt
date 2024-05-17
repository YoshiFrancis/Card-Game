add_library(unogame STATIC Hand.cpp Player.cpp UnoCard.cpp Deck.cpp PlayerContainer.cpp CardGame.cpp)
target_include_directories(unogame PUBLIC ${PROJECT_SOURCE_DIR}/Card-Game/include ${PROJECT_SOURCE_DIR}/include)
