#include "bash.h"

namespace Bash {
std::string Popen(std::string cmd) {
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw Exceptions::System::kBashError;
    char buffer[1145] = {0};
    while (fread(buffer, 1, 1144, pipe));
    if (pclose(pipe)) throw Exceptions::System::kCommandError;
    return buffer;
}
}