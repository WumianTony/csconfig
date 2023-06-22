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

static std::vector<std::string> Parse(std::stringstream& raw_result, 
    bool (*validation)(std::string) 
    = [](std::string line) {
        return true;
    }
) {
    std::vector<std::string> result;
    std::string temp;
    while (std::getline(raw_result, temp)) {
        if (validation(temp)) {
            result.push_back(temp);
        }
    }
    return result;
}

std::string fetchExecPath() {
    return Popen("cd");
}

bool isPathExist(std::string path) {
    std::string result = Popen("if exist \"" + path + "\" (echo 1) else (echo 0)");
    return std::stoi(result);
}

std::vector<std::string> fetchAllSteamPaths() {
    std::stringstream raw_result(Popen("cd / & dir /s /b Steam"));
    return Parse(raw_result, [](std::string line) {
        return line.find("Steam", line.find_last_of('\\')) != std::string::npos && isPathExist(line + "/userdata");
    });
}

std::vector<std::string> fetchAllUsers(std::string steam_path) {
    std::stringstream raw_result(Popen("cd " + steam_path + "/userdata & dir /b"));
    return Parse(raw_result);
}

}