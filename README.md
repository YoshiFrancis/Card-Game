### Overview of interface design:
IServer:				Listens for requests and handles them. Responsible for creating games, ending games, and adding players to games
IClient:				The layer between clients and their players. The client represents the soul of the player. 
IGame:					The game interface. Will create game on new thread when constructed. Will send messages to server to send out to clients. Will also receive messages from server
						via its game id
IPlayer:				The player class. Connected to a IClient class to receive inptus from the client. Will run locally on the server and will be responsible for playing and drawing
						cards. Will receive all commands from user.
IPlayerContainer:		Player container class. Will hold all of the players.
IDeck:					The deck interface. Will abstract for all the different kinds of decks to make implementing new card games easier. Examples of games: Uno, Crazy Eight, Solitaire, etc.
						Will be responsible for creating deck, randomizing deck, and drawing new cards
IHand:					The hand of the player interface. Will hold all the cards a player currently has.
ICard:					Card interface. Will interfacee for all the different kinds of cards.


### NEW IMPLEMENTATION OF SERVER/CLIENT PIPELINE (April 21, 2024)

Scenario gets a request for a creation of a game:
1. Server gets set up and listens for request
2. Client sets up connection and sends request to start up a game
3. Server creates game (game creates own thread to run on)
4. Server sends game id to client and client uses id to join the game
5. all conncections requestion to join game with the game id are added totothe game

Game requests client to play a card or draw:
1. Game sends message to server to send to a client
2. Server receives message and sends to the client
3. Client receives message and is asked to respond
4. Client responds and sends message back to the server with their specific gameId to signify which game they are a part of
5. Server receives message and sends to the game with the specified gameId
6. Game checks for valid player and handles the message
7. Game goes on to next player and repeats cycle
