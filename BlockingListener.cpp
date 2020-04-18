//
// Created by John Stanhope on 12/13/19.
//

#include "BlockingListener.h"
#include "SystemError.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <cerrno>
#include <netinet/in.h>
#include <unistd.h>

BlockingListener::BlockingListener(int port) : _port(port), _listeningFd(-1)
{
    _listeningFd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (_listeningFd == -1) {
        throw SystemError(__FUNCTION__, "socket", errno);
    }
}

BlockingListener::~BlockingListener()
{
    if (_listeningFd != -1) {
        ::shutdown(_listeningFd, SHUT_RDWR);
        ::close(_listeningFd);
    }
}


void BlockingListener::bind()
{
    struct sockaddr_in serverAddress = { 0 };
    serverAddress.sin_len = sizeof(serverAddress);
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(_port); // TODO: do not hard code
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    int result = ::bind(_listeningFd, reinterpret_cast<const sockaddr *>(&serverAddress), sizeof(serverAddress));
    if (result == -1) {
        throw SystemError(__FUNCTION__, "bind", errno);
    }
}

void BlockingListener::listen()
{
    int backlog = 5;
    auto result = ::listen(_listeningFd, backlog);
    if (result == -1) {
        throw SystemError(__FUNCTION__, "listen", errno);
    }
}

std::shared_ptr<BlockingChannel> BlockingListener::accept()
{
    struct sockaddr_in clientAddress = { 0 };
    socklen_t clientAddressSize = sizeof(struct sockaddr_in);
    int clientFd = ::accept(_listeningFd, reinterpret_cast<sockaddr *>(&clientAddress), &clientAddressSize);
    if (clientFd == -1) {
        throw SystemError(__FUNCTION__, "accept", errno);
    }
    return std::make_shared<BlockingChannel>(clientFd);
}