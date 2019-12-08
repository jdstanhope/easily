//
// Created by John Stanhope on 12/8/19.
//

#ifndef EASILY_COMMANDLINE_H
#define EASILY_COMMANDLINE_H


#include <vector>

class CommandLine {

public:
    CommandLine(int count, const char **arguments);

private:
    std::vector<std::string> _files;
};


#endif //EASILY_COMMANDLINE_H
