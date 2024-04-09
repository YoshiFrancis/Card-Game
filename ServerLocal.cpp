#include "ServerLocal.h"

bool ServerLocal::sendMessage(const IClient& client, std::string_view message) {

    return true;
}
void ServerLocal::handleMessage(const IClient& sender, std::string_view message) {

}
std::string_view ServerLocal::receiveMessage() {

    return "Hello";

}
void ServerLocal::shutdown() {

}
void ServerLocal::endConnection(const IClient& client) {

}

