#include "bash.h"

namespace Bash {

static std::string Popen(std::string cmd) {
    debug_info << cmd; ddump();
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw Exceptions::Bash::kBashError;
    char buffer[1145] = {0};
    while (fread(buffer, 1, 1144, pipe));
    debug_info << buffer; ddump();
    if (pclose(pipe)) throw Exceptions::Bash::kCommandError;
    return buffer;
}

static std::vector<std::string> Parse(std::stringstream& raw_result, 
    bool (*validation)(std::string, std::string) 
    = [](std::string line, std::string suffix) {
        return true;
    }
) {
    std::vector<std::string> result;
    std::string temp;
    while (std::getline(raw_result, temp)) {
        if (validation(temp, "")) {
            result.push_back(temp);
        }
    }
    for (auto each : result) debug_info << each << "\n"; ddump();
    return result;
}

std::string fetchExecPath() {
    return Popen("cd");
}

bool isPathExist(std::string path) {
    std::string result = Popen("if exist \"" + path + "\" (echo 1) else (echo 0)");
    return std::stoi(result);
}

std::vector<std::string> fetchAllSteamPaths(std::string suffix) {
    std::stringstream raw_result(Popen("cd / & dir /s/b Steam"));
    return Parse(raw_result, [](std::string line, std::string suffix) {
        return line.find("Steam", line.find_last_of('\\')) != std::string::npos && isPathExist(line + suffix);
    });
}

std::vector<std::string> fetchAllUsers() {
    std::stringstream raw_result(Popen("cd \"" + steam_path + "\\userdata\" & dir /b"));
    return Parse(raw_result);
}

void mkdir() {
    std::string directory_path = Const::Path::Package();
    for (auto each : Const::Path::Custom::directories) {
        Popen("mkdir \"" + Const::Path::Package() + "\\" + each + "\"");
    }
}

int fetchLatestBackup() {
    std::string backup_path = Const::Path::Backups();
    std::stringstream raw_result(Popen("cd \"" + backup_path + "\" & dir /b/o:d"));
    std::vector<std::string> backups = Parse(raw_result);
    debug_info << backups[backups.size() - 1]; ddump();
    return std::stoi(backups[backups.size() - 1]);
}

void newBackup(int backup_order) {
    std::string directory_path = Const::Path::Package();
    std::string backup_path = Const::Path::Backups();
    std::string target_path = backup_path + '\\' + std::to_string(backup_order);
    if (isPathExist(target_path)) {
        Popen("rd /s/q \"" + target_path + '\"');
    }
    Popen("xcopy /e/h/i/y \"" + directory_path + "\" \"" + target_path + '\"');
}

void modifyAutoExec() {
    std::string autoexec_path = Const::Path::GameCfg() + "\\autoexec.cfg";
    std::vector<std::string> buffer;
    File::Read(autoexec_path, buffer);
    if (std::find(buffer.begin(), buffer.end(), "exec wumiancfg-csgo/default") == buffer.end()) {
        std::ofstream fout(autoexec_path, std::ios::app);
        fout << "\nexec wumiancfg-csgo/default\n";
        fout.close();
    }
}

}