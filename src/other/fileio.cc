#include "fileio.h"

namespace File {

std::string fetchUserNickname(std::string steam_path, std::string user_code) {
    // std::locale::global(std::locale(""));
    std::ifstream fin(steam_path + "/userdata/" + user_code + "/config/localconfig.vdf");
    if (!fin.is_open()) throw Exceptions::Steam::kBadFile;
    const std::string target = "\"PersonaName\"\t\t\"";
    std::string line;
    while (!fin.eof()) {
        std::getline(fin, line);
        size_t pos = line.find(target);
        if (pos != std::string::npos) {
            std::string nickname = line.substr(pos + target.length());  
            size_t endPos = nickname.find('\"');
            nickname = nickname.substr(0, endPos);
            fin.close();
            return nickname;
        }
    }
    fin.close();
    throw Exceptions::Steam::kUserNicknameNotFound;
}

}