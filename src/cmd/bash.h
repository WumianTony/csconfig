#ifndef _BASH_H_
#define _BASH_H_

#include "global.h"

namespace Bash {

    bool isPathExist(std::string path);

    std::string fetchExecPath();
    std::vector<std::string> fetchAllSteamPaths();
    std::vector<std::string> fetchAllUsers(std::string steam_path);
}

#endif