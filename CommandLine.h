//
// Created by John Stanhope on 12/8/19.
//

#ifndef EASILY_COMMANDLINE_H
#define EASILY_COMMANDLINE_H


#include <vector>

class CommandLine {

public:
    CommandLine(int count, const char **arguments);

    int port() const { return _port; }

private:
    std::vector<std::string> _files;
    int _port = 5000;
};


#endif //EASILY_COMMANDLINE_H
