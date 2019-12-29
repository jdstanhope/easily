//
// Created by John Stanhope on 12/29/19.
//

#ifndef EASILY_REQUEST_H
#define EASILY_REQUEST_H


#include <string>

class Request {
public:
    Request(std::string data);

private:
    std::string _data;
};


#endif //EASILY_REQUEST_H
