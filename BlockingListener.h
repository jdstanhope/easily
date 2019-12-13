//
// Created by John Stanhope on 12/13/19.
//

#ifndef EASILY_BLOCKINGLISTENER_H
#define EASILY_BLOCKINGLISTENER_H

#include <memory>
#include "BlockingChannel.h"

class BlockingListener {
public:
    explicit BlockingListener(int port);
    ~BlockingListener();

    void bind();
    void listen();
    std::shared_ptr<BlockingChannel> accept();

private:
    int _port;
    int _listeningFd;
};

#endif //EASILY_BLOCKINGLISTENER_H
