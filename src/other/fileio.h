#ifndef _FILEIO_H_
#define _FILEIO_H_

#include "global.h"

namespace File {
    std::string fetchUserNickname(std::string steam_path, std::string user_code);
}

#endif