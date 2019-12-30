#include <iostream>
#include "CommandLine.h"
#include "WebServer.h"
#include "Logger.h"

int main(int argc, const char* argv[]) {
    try {
        auto commandLine = std::make_shared<CommandLine>(argc, argv);
        auto logger = std::make_shared<Logger>(commandLine);
        auto server = std::make_shared<WebServer>(commandLine, logger);
        return server->run();
    } catch (std::invalid_argument& invalid) {
        std::cerr << "error: invalid argument " << invalid.what() << std::endl;
    }
    return 0;
}
