#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <iostream>
#include <string>
#include <typeinfo>

namespace Exceptions {

    enum class Level {
        kInfo = 0,
        kDebug,
        kWarning,
        kError
    };

    struct Error {
        int code;
        Level level;
        std::string message;
    };

    const Error kSuccess = {0, Level::kInfo};

    namespace System {
        const Error
        kStdException               = {1,   Level::kError,   ""},
        kUnknownError               = {2,   Level::kError,   "Unknown exception"},
        kBashError                  = {11,  Level::kError,   "Cannot access bash"},
        kCommandError               = {12,  Level::kError,   "Cannot execute such command"},
        kCommandParamOutOfBounds    = {13,  Level::kWarning, "Command parameter out of bounds"};
    }

    std::string fetchScope(Error error);
    void perr(Error error);
}

#endif