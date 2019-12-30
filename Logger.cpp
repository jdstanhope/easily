//
// Created by John Stanhope on 12/30/19.
//

#include <iostream>
#include "Logger.h"

Logger::Logger(std::shared_ptr<CommandLine> commandLine) {
}

void Logger::error(const std::string &message) {
    std::cerr << "error: " << message << std::endl;
}

void Logger::warning(const std::string &message) {
    std::cout << "warning: " << message << std::endl;
}

void Logger::info(const std::string &message) {
    std::cout << "info: " << message << std::endl;
}
