TO DO LIST

1. Get Tests running with CMake and ctest -- DONE
2. Test UnoCard.cpp -- DONE
3. Create and test HandLocal.cpp -- DONE
4. Create and test PlayerLocal.cpp -- DONE
5. Create and test PlayerContainer.cpp
6. Create and test UnoDeck.cpp -- SCRATCHED TO Deck.cpp -- DONE
7. Create and test Client.cpp 
8. Create and test HandlerLocal.cpp -- NEED
9. Create and test Server.cpp -- NEED
10. Create and test CardGame.cpp -- NEED
11. Create and test ServerSockets.cpp
12. Create and test ClientSockets.cpp
13. Create and test CommunicatorSockets.cpp
14. Create and test UnoGameSockets.cpp or GameSockets.cpp 


need to create pipeline between handler, server, cardgame, and client.

Client -> server -> handler -> game/client/server
Game -> handler -> server/client

everything goes through the handler.
Only handler will be changed to determine if the game is local, websockets or http
Server is also changed
