#ifndef HANDLERLOCAL_H
#define HANDLERLOCAL_H

#include "IServer.h"
#include "IHandler.h"


class HandlerLocal : public IHandler {

public:
    HandlerLocal() { }
    bool sendMessage(const IClient& client, std::string_view message) override;
    void handleMessage(const IClient& client, std::string_view message) override;
    void receiveMessage(const IClient& client, std::string_view message) override;
    void shutdown() override; // i honestly do not know what this is for
							  // perhaps to end all current conncections?
    void endConnection(const IClient& client) override;


    ~HandlerLocal() = default;
};

#endif
