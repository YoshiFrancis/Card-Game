#include "HandlerLocal.h"

bool HandlerLocal::sendMessage(const IClient& client, std::string_view message) {

    return true;
}
void HandlerLocal::handleMessage(const IClient& sender, std::string_view message) {

}
std::string_view HandlerLocal::receiveMessage() {

    return "Hello";

}
void HandlerLocal::shutdown() {

}
void HandlerLocal::endConnection(const IClient& client) {

}

