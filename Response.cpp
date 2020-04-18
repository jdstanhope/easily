//
// Created by John Stanhope on 12/29/19.
//

#include "Response.h"

Response::Response(std::shared_ptr<Request> request) : _request(request) {
}

std::string Response::data() const {
    return std::string("HTTP/1.1 200 OK\r\n\r\nHello World\r\n");
}
