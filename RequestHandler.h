//
// Created by John Stanhope on 12/29/19.
//

#ifndef EASILY_REQUESTHANDLER_H
#define EASILY_REQUESTHANDLER_H

#include <memory>
#include "Response.h"
#include "Request.h"

class RequestHandler {
public:
    std::shared_ptr<Response> handle(std::shared_ptr<Request> request);
};


#endif //EASILY_REQUESTHANDLER_H
