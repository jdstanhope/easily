//
// Created by John Stanhope on 12/19/19.
//

#ifndef EASILY_SYSTEMERROR_H
#define EASILY_SYSTEMERROR_H

#include <exception>
#include <string>

class SystemError : public std::exception {
public:
    SystemError(const char* appCall, const char* systemCall, int code);

    int code() const;
    std::string appCall() const;
    std::string systemCall() const;
    std::string codeString() const;
    const char* what() const _NOEXCEPT override ;

private:
    std::string _appCall;
    std::string _sysCall;
    int _code;
    std::string _message;

    void formatWhat();

    const char *codeAsString();
};


#endif //EASILY_SYSTEMERROR_H
