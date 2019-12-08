//
// Created by John Stanhope on 12/8/19.
//

#include "CommandLine.h"
#include <string>
#include <sstream>
#include <strstream>

CommandLine::CommandLine(int count, const char **arguments) {
    for (int i=1 ; i<count ; ++i) {
        auto arg = arguments[i];
        auto length = strlen(arg);
        if (arg[0] == '-') {
            if (length > 1) {
                if (arg[1] == '-') {
                    // long name
                    if (length > 2) {
                        auto longName = arg + 2;
                    } else {
                        throw std::invalid_argument("--");
                    }
                } else {
                    // short name
                    auto shortName = arg + 1;
                }
            } else {
                // bad argument
                throw std::invalid_argument("-");
            }
        } else {
            _files.emplace_back(arg);
        }
    }
}
