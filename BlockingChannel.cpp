//
// Created by John Stanhope on 12/13/19.
//

#include "BlockingChannel.h"
#include <cassert>
#include <unistd.h>
#include <algorithm>
#include <cerrno>

BlockingChannel::BlockingChannel(int fd) : _fd(fd), _error(false)
{
    assert(_fd != -1);
}

BlockingChannel::~BlockingChannel()
{
    ::close(_fd);
}

std::string BlockingChannel::read()
{
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
            switch (errno) {
                case EAGAIN:
                    break;
                case EBADF:
                    break;
                case EFAULT:
                    break;
                case EINTR:
                    break;
                case EINVAL:
                    break;
                case EIO:
                    break;
                case EISDIR:
                    break;
            }
            throw std::runtime_error("");
        }
    }
    return std::move(request);
}