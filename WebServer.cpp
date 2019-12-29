//
// Created by John Stanhope on 12/8/19.
//

#include "WebServer.h"
#include "BlockingListener.h"
#include "Request.h"
#include <utility>

WebServer::WebServer(std::shared_ptr<CommandLine> commandLine)
: _commandLine(std::move(commandLine)) {
    _requestHandler = std::make_shared<RequestHandler>();
}

int WebServer::run()
{
    try {
        auto listener = std::make_shared<BlockingListener>(_commandLine->port());
        listener->bind();
        listener->listen();
        _running = true;
        while (_running) {
            auto channel = listener->accept();
            try {
                auto data = channel->read();
                auto request = std::make_shared<Request>(data);
                auto response = _requestHandler->handle(request);
                channel->write(response->data());
            } catch (std::exception& e) {
                // TODO: log errors
            }
        }
        return 0;
    } catch (std::exception& e) {
        return -1;
    }
}
