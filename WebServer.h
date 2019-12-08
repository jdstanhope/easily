//
// Created by John Stanhope on 12/8/19.
//

#ifndef EASILY_WEBSERVER_H
#define EASILY_WEBSERVER_H


#include "CommandLine.h"

class WebServer {

public:
    explicit WebServer(const CommandLine& commandLine);

    int run();

private:
};


#endif //EASILY_WEBSERVER_H
