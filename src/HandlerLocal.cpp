#include "HandlerLocal.h"
#include "IClient.h"
#include <iostream>

bool HandlerLocal::sendMessage(const IClient& client, std::string_view message) {
  	return client.receiveMessage(message);
}

void HandlerLocal::handleMessage(const IClient& client, std::string_view message) {
    std::cout << message << "\n";
	if (message[0] == 'J') {
		// user is joining the game
		// will need to ask for username 
		// bind client to a player class
	} else if (message[0] == 'P') {
		// user is playing card/game
		// access the client's player class to play game
	} else if (message[0] == 'H') {
		// user is asking for instructions on how to play
		// send client a message of helpful text (probably read from a file)
	} else if (message[0] == 'L') {
		// client wants to leave, so end connection
		endConnection(client);
	}
	else {
		// user sent invalid message 
		// send error message to client
	}
}

void HandlerLocal::receiveMessage(const IClient& client, std::string_view message) {
	// thinking of starting a new thread each time a message is received
	// would utilize threading to concurrently handle messages
    handleMessage(client, message);
}

void HandlerLocal::endConnection(const IClient& client) {
   // remove player from game
   // end all connections with the player
}

void HandlerLocal::shutdown() {

}



