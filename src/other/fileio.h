#ifndef _FILEIO_H_
#define _FILEIO_H_

#include "global.h"

namespace File {
    std::string fetchUserNickname(std::string user);

    void Read(std::string file_path, void (func)(std::string) = [](std::string temp) {});

    void Write(std::unordered_map<std::string, std::stringstream> buffer);
}

#endif