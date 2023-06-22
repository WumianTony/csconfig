#include "bash.h"

namespace Bash {

static std::string Popen(std::string cmd) {
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw Exceptions::Bash::kBashError;
    char buffer[1145] = {0};
    while (fread(buffer, 1, 1144, pipe));
    if (pclose(pipe)) throw Exceptions::Bash::kCommandError;
    return buffer;
}

std::string getExecPath() {
    return Popen("cd");
}

bool isPathExist(std::string path) {
    std::string result = Popen("if exist \"" + path + "\" (echo 1) else (echo 0)");
    return std::stoi(result);
}

std::vector<std::string> fetchAllSteamPaths() {
    std::stringstream raw_result(Popen("cd / & dir /s /b Steam"));
    std::vector<std::string> result;
    std::string temp;
    while (std::getline(raw_result, temp)) {
        if (temp.find("Steam", temp.find_last_of('\\')) != std::string::npos && isPathExist(temp + "/userdata")) {
            result.push_back(temp);
        }
    }
    return result;
}

}