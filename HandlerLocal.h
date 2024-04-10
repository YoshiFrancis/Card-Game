#ifndef HANDLERLOCAL_H
#define HANDLERLOCAL_H

#include "IServer.h"

class HandlerLocal : public IHandler {

public:
    HandlerLocal() = default;

    bool sendMessage(const IClient& client, std::string_view message) override;
    void handleMessage(const IClient& sender, std::string_view message) override;
    std::string_view receiveMessage() override;
    void shutdown() override;
    void endConnection(const IClient& client) override;


};

#endif
