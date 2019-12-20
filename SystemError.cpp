//
// Created by John Stanhope on 12/19/19.
//

#include "SystemError.h"
#include <cerrno>
#include <sstream>

SystemError::SystemError(const char* appCall, const char* systemCall, int code)
: _appCall(appCall), _sysCall(systemCall), _code(code) {
    formatWhat();
}

std::string SystemError::appCall() const {
    return _appCall;
}

std::string SystemError::systemCall() const {
    return _sysCall;
}

int SystemError::code() const {
    return _code;
}

const char* SystemError::what() const _NOEXCEPT {
    return _message.c_str();
}

void SystemError::formatWhat() {
    std::ostringstream stream;
    stream << "error(" << _code << ", " << codeAsString() << "): from " << _appCall << " when calling " << _sysCall << "()";
    _message = stream.str();
}

const char *SystemError::codeAsString() {
    switch (_code) {
        case EACCES:
            return "EACCES";
        case EADDRINUSE:
            return "EADDRINUSE";
        case EADDRNOTAVAIL:
            return "EADDRNOTAVAIL";
        case EAFNOSUPPORT:
            return "EAFNOSUPPORT";
        case EBADF:
            return "EBADF";
        case EDESTADDRREQ:
            return "EDESTADDRREQ";
        case EFAULT:
            return "EFAULT";
        case EINVAL:
            return "EINVAL";
        case ENOTSOCK:
            return "ENOTSOCK";
        case EOPNOTSUPP:
            return "EOPNOTSUPP";
        case ECONNABORTED:
            return "ECONNABORTED";
        case EINTR:
            return "EINTR";
        case EMFILE:
            return "EMFILE";
        case ENFILE:
            return "ENFILE";
        case ENOMEM:
            return "ENOMEM";
        case EWOULDBLOCK:
            return "EWOULDBLOCK";
        case EIO:
            return "EIO";
        case EISDIR:
            return "EISDIR";
        default:
            return "UNKNOWN";
    }
}
