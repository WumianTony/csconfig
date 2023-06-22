#ifndef _BASH_H_
#define _BASH_H_

#include <string>
#include "exceptions.h"

namespace Bash {
    std::string Popen(std::string cmd);
}

#endif