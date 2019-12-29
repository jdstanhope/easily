//
// Created by John Stanhope on 12/13/19.
//

#include "BlockingChannel.h"
#include "SystemError.h"
#include <cassert>
#include <unistd.h>
#include <algorithm>
#include <cerrno>
#include <sys/socket.h>

BlockingChannel::BlockingChannel(int fd) : _fd(fd), _error(false) {
    assert(_fd != -1);
}

BlockingChannel::~BlockingChannel() {
    ::shutdown(_fd, SHUT_RDWR);
    ::close(_fd);
}

std::string BlockingChannel::read() {
    std::string request;
    size_t readBufferSize = 1024;
    auto readBuffer = std::unique_ptr<char>(new char[readBufferSize]);
    while (true) {
        auto readSize = ::read(_fd, readBuffer.get(), readBufferSize);
        if (readSize > 0) {
            request.append(readBuffer.get(), readSize);
            if (readSize == readBufferSize) {
                // read more
                continue;
            } else {
                // done
                break;
            }
        } else if (readSize == 0) {
            // done
            break;
        } else if (readSize == -1) {
            _error = true;
            throw SystemError(__FUNCTION__, "read", errno);
        }
    }
    return std::move(request);
}

void BlockingChannel::write(const std::string &data) {
    int result = ::write(_fd, data.c_str(), data.length());
    if (result != data.length()) {
        throw SystemError(__FUNCTION__, "write", errno);
    }
}
