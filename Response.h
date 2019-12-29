//
// Created by John Stanhope on 12/29/19.
//

#ifndef EASILY_RESPONSE_H
#define EASILY_RESPONSE_H

#include <string>

class Response {
public:
    std::string data() const { return std::string("Hello World\r\n"); }
};

#endif //EASILY_RESPONSE_H
