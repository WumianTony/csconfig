#ifndef _BASH_H_
#define _BASH_H_

#include <sstream>
#include <string>
#include <vector>
#include "const.h"
#include "exceptions.h"

namespace Bash {

    bool isPathExist(std::string path);

    std::string getExecPath();
    std::vector<std::string> fetchAllSteamPaths();
}

#endif