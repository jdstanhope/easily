//
// Created by John Stanhope on 12/13/19.
//

#ifndef EASILY_BLOCKINGCHANNEL_H
#define EASILY_BLOCKINGCHANNEL_H

#include <string>

class BlockingChannel {
public:
    explicit BlockingChannel(int fd);
    ~BlockingChannel();

    std::string read();

private:
    int _fd;
    bool _error;
};

#endif //EASILY_BLOCKINGCHANNEL_H
