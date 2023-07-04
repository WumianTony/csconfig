#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include "global.h"

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
        kUnknownError               = {2,   Level::kError,   "Unknown exception"};
    }

    namespace Steam {
        const Error
        kPathNotFound               = {101, Level::kWarning, "Steam path not found"},
        kUserNotFound               = {111, Level::kWarning, "Steam user not found"},
        kUserNicknameNotFound       = {112, Level::kWarning, "Steam user nickname not found"},
        kBadFile                    = {121, Level::kError  , "Cannot open this \".vdf\" file"};
    }

    namespace Bash {
        const Error
        kBashError                  = {201, Level::kError,   "Cannot access bash"},
        kCommandError               = {211, Level::kError,   "Cannot execute such command"},
        kCommandParamOutOfBounds    = {212, Level::kWarning, "Command parameter out of bounds"},
        kUIEmptyChoice              = {299, Level::kError,   "Empty choice"};
    }

    namespace Config {
        const Error
        kArgNotFound                = {301, Level::kError,   "Argument not found"},
        kBindNotFound               = {302, Level::kError,   "Bind not found"};
    }

    std::string fetchScope(Error error);
    void perr(Error error);
}

#endif