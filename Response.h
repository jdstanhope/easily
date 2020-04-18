//
// Created by John Stanhope on 12/29/19.
//

#ifndef EASILY_RESPONSE_H
#define EASILY_RESPONSE_H

#include <string>
#include "Request.h"

class Response {
public:
    explicit Response(std::shared_ptr<Request> request);

    std::string data() const;

private:
    std::shared_ptr<Request> _request;
};

#endif //EASILY_RESPONSE_H
