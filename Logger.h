//
// Created by John Stanhope on 12/30/19.
//

#ifndef EASILY_LOGGER_H
#define EASILY_LOGGER_H


#include <memory>
#include "CommandLine.h"

class Logger {
public:
    Logger(std::shared_ptr<CommandLine> commandLine);

    void error(const std::string& message);
    void warning(const std::string& message);
    void info(const std::string& message);

private:
};


#endif //EASILY_LOGGER_H
