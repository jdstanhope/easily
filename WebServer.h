//
// Created by John Stanhope on 12/8/19.
//

#ifndef EASILY_WEBSERVER_H
#define EASILY_WEBSERVER_H


#include "CommandLine.h"
#include "RequestHandler.h"

class WebServer {

public:
    explicit WebServer(std::shared_ptr<CommandLine> commandLine);

    int run();

private:
    std::shared_ptr<CommandLine> _commandLine;
    std::shared_ptr<RequestHandler> _requestHandler;
    bool _running = false;
};


#endif //EASILY_WEBSERVER_H
