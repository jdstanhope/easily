#include <iostream>
#include "CommandLine.h"
#include "WebServer.h"

int main(int argc, const char* argv[]) {
    try {
        CommandLine commandLine(argc, argv);
        WebServer server(commandLine);
        return server.run();
    } catch (std::invalid_argument& invalid) {
        std::cerr << "error: invalid argument " << invalid.what() << std::endl;
    }
    return 0;
}
