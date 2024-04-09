#ifndef SERVERLOCAL_H
#define SERVERLOCAL_H

#include "IServer.h"

class ServerLocal : public IServer {

public:
    ServerLocal() = default;

    bool sendMessage(const IClient& client, std::string_view message) override;
    void handleMessage(const IClient& sender, std::string_view message) override;
    std::string_view receiveMessage() override;
    void shutdown() override;
    void endConnection(const IClient& client) override;


};

#endif