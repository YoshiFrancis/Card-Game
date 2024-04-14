# Card-Game

Each game will be ran by one ICommunicator
Whenever a new game is started, create a new IGame class to host the new game
IGame should contain the 
1. ICommunicator to facilate communication between host and all clients (IServer and IClient)
2. IPlayerContainer to hold all the players in the game
3. IDeck to keep track of the deck (and also be the dealer)

Each IPlayer in the IPlayerContainer will be associated to a client
IGame will be responsible for running the game
A card will be drawn and all operatioins will be done locally in the IGame class
Then all operations that happened will be forwarded to all clients

Lower Level (happens on the host):
- Game runs
- All card operations happen
- Creation of new thread (IGame) to run game
- Container holding all current running games

Classes:
IGame, IPlayer, IDeck, IPlayerContainer

Needed Class:
ICommunicatorStorage 
    - will hold all IGame and their respective ICommunicator
    - Will create new IGame thread whenever a request for a new game from client appears

Higher Level (Networking Side):
- Communication between client and host

Classes:
ICommunicator, IClient, IServer, IGame

How players will join:
Player will send request to join a game (using a given passcode or IP) via sending to ICommunicatorStorage
ICommunicatorStorage will check all IGame ICommunicator's IServer looking for right room to send new client to
IClient class will be allocated for new client if successful
IPlayer class created with IClient as member variagle and pushed into the IPlayerContainer

Highest Layer to Lowest layer
ICommunicatorStorage (might as well be IGameStorage)
    - IGame
        - ICommunicator
            - IServer
        - IPlayerContainer
            - IPlayer
                - IClient
        - IDeck
            - ICard

# Implemenetation #2

Highest Layer - Lowest layer
ICommunicatorStorage
    -ICommunicator
        - IServer
        - IClient
            - IPlayer
        - IGame
            - IPlayerContainer
                - IPlayer
            - IDeck
                - ICard

Problems:
1. May be hard to get info from the server to the Igame due to the disconnection and IGame not having direct access to messages
2. IGame and clients are disconnected - two separate entities to track over IPlayer
3. IGame has to constantly wait for other classes to continue running which are not in its control
4. Constant propogation upward
4. Overall: I do not like the lack of control IGame has

Pros:
1. Easy to separate the lower side (the IGame) from the higher level side (the networking aspects)
