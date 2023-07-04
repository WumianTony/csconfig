#include "fileio.h"

namespace File {

std::string fetchUserNickname(std::string user) {
    // std::locale::global(std::locale(""));
    std::ifstream fin(steam_path + "/userdata/" + user + "/config/localconfig.vdf");
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

void Read(std::string file_path, void (func)(std::string)) {
    debug_info << file_path; ddump();
    std::ifstream fin(file_path);
    std::string line;
    debug_info << "114514?"; ddump();
    while (!fin.eof()) {
        std::getline(fin, line);
        debug_info << "line:\t" << line; ddump();
        func(line);
    }
}

void Read(std::string file_path, std::vector<std::string>& buffer) {
    std::ifstream fin(file_path);
    std::string line;
    while (!fin.eof()) {
        std::getline(fin, line);
        buffer.push_back(line);
        debug_info << "line:\t" << line; ddump();
    }
}

void Write(std::unordered_map<std::string, std::stringstream> buffer) {
    for (const auto& [path, content] : buffer) {
        std::ofstream fout(Const::Path::Package() + "\\" + path);
        fout << content.str();
        fout.close();
    }
}

void Log(std::map<std::string, std::string> log) {
    debug_info << "log 001"; ddump();
    std::ofstream fout("log.txt");
    debug_info << "log 002"; ddump();
    for (const auto& [key, info] : log) {
        debug_info << "log 003 " << key << " " << info; ddump();
        fout << std::setw(18) << std::setfill(' ') << key << "  " << info << std::endl;
        debug_info << "log 004 "; ddump();
    }
    fout.close();
    debug_info << "log 005"; ddump();
}

}