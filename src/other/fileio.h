#ifndef _FILEIO_H_
#define _FILEIO_H_

#include "global.h"

namespace File {
    std::string fetchUserNickname(std::string steam_path, std::string user_code);

    void Read(std::string file_path, void (func)(std::string) = [](std::string temp) {});
}

#endif