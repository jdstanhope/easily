//
// Created by John Stanhope on 12/13/19.
//

#include "BlockingListener.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <cerrno>
#include <netinet/in.h>
#include <unistd.h>

BlockingListener::BlockingListener(int port) : _port(port), _listeningFd(-1)
{
    _listeningFd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (_listeningFd == -1) {
        switch (errno) {
            case EACCES:
                break;
            case EAFNOSUPPORT:
                break;
            case EMFILE:
                break;
            case ENFILE:
                break;
            case ENOBUFS:
                break;
            case ENOMEM:
                break;
            case EPROTONOSUPPORT:
                break;
            case EPROTOTYPE:
                break;
        }
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
        switch (errno) {
            case EACCES:
                break;
            case EADDRINUSE:
                break;
            case EADDRNOTAVAIL:
                break;
            case EAFNOSUPPORT:
                break;
            case EBADF:
                break;
            case EDESTADDRREQ:
                break;
            case EFAULT:
                break;
            case EINVAL:
                break;
            case ENOTSOCK:
                break;
            case EOPNOTSUPP:
                break;
        }
        throw std::runtime_error("");
    }
}

void BlockingListener::listen()
{
    int backlog = 5;
    auto result = ::listen(_listeningFd, backlog);
    if (result == -1) {
        switch (errno) {
            case EACCES:
                break;
            case EBADF:
                break;
            case EDESTADDRREQ:
                break;
            case EINVAL:
                break;
            case ENOTSOCK:
                break;
            case EOPNOTSUPP:
                break;
        }
        throw std::runtime_error("");
    }}

std::shared_ptr<BlockingChannel> BlockingListener::accept()
{
    struct sockaddr_in clientAddress = { 0 };
    socklen_t clientAddressSize = sizeof(struct sockaddr_in);
    int clientFd = ::accept(_listeningFd, reinterpret_cast<sockaddr *>(&clientAddress), &clientAddressSize);
    if (clientFd == -1) {
        switch (errno) {
            case EBADF:
                break;
            case ECONNABORTED:
                break;
            case EFAULT:
                break;
            case EINTR:
                break;
            case EINVAL:
                break;
            case EMFILE:
                break;
            case ENFILE:
                break;
            case ENOMEM:
                break;
            case ENOTSOCK:
                break;
            case EOPNOTSUPP:
                break;
            case EWOULDBLOCK:
                break;
        }
        throw std::runtime_error("");
    }
    return std::make_shared<BlockingChannel>(clientFd);
}