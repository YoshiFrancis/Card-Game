#ifndef HANDLERLOCAL_H
#define HANDLERLOCAL_H

#include "IServer.h"
#include "IHandler.h"


class HandlerLocal : public IHandler {

public:
    HandlerLocal() { }
    bool sendMessage(const IClient& client, std::string_view message) override;
    void handleMessage(std::string_view message) override;
    void receiveMessage(std::string_view message) override;
    void shutdown() override;
    void endConnection(const IClient& client) override;


    ~HandlerLocal() = default;
};

#endif
