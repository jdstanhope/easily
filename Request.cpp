//
// Created by John Stanhope on 12/29/19.
//

#include "Request.h"
#include <utility>

Request::Request(std::string data)
: _data(std::move(data)) {

}
