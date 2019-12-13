//
// Created by John Stanhope on 12/8/19.
//

#include "WebServer.h"
#include "BlockingListener.h"

WebServer::WebServer(const CommandLine& commandLine)
{
}

int WebServer::run()
{
    try {
        auto listener = std::make_shared<BlockingListener>(5000);
        listener->bind();
        listener->listen();
        auto channel = listener->accept();
        auto request = channel->read();
        return 0;
    } catch (std::exception& e) {
        return -1;
    }
}

