//
// Created by John Stanhope on 12/8/19.
//

#include "WebServer.h"
#include "BlockingListener.h"
#include "Request.h"
#include <utility>

WebServer::WebServer(std::shared_ptr<CommandLine> commandLine, std::shared_ptr<Logger> logger)
: _commandLine(std::move(commandLine)), _logger(std::move(logger))
{
    _requestHandler = std::make_shared<RequestHandler>();
}

int WebServer::run()
{
    try {
        _logger->info("starting blocking listener");
        auto listener = std::make_shared<BlockingListener>(_commandLine->port());
        _logger->info("binding");
        listener->bind();
        _logger->info("listening");
        listener->listen();
        _running = true;
        while (_running) {
            _logger->info("waiting for connection");
            auto channel = listener->accept();
            try {
                _logger->info("accepted connection");
                auto data = channel->read();
                _logger->info(data);
                auto request = std::make_shared<Request>(data);
                auto response = _requestHandler->handle(request);
                channel->write(response->data());
            } catch (std::exception& e) {
                _logger->error(e.what());
            }
        }
        return 0;
    } catch (std::exception& e) {
        _logger->error(e.what());
        return -1;
    }
}

