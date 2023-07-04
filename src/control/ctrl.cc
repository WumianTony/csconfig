#include "ctrl.h"

std::string steam_path, user_code;

namespace Control {

void Version() {
    system("cls");
    std::cout 
        << "Counter Strike Config Generator\n"
        << "Version      1.0\n"
        << "Game         Counter Strike: Global Offensive\n"
        << "Author       Wumian_Tony\n"
        << "Github Repo  https://github.com/WumianTony/csconfig\n"
        << "Lanzou Cloud https://bjea.lanzoup.com/csconfig\n"
        << "Bilibili     https://space.bilibili.com/412625865\n";
}

void ConfigVersion() {
    system("cls");
    std::cout 
        << "Wumian's Config\n"
        << "Version      1.6\n"
        << "Game         Counter Strike: Global Offensive\n"
        << "Author       Wumian_Tony\n"
        << "Github Repo  https://github.com/WumianTony/wumiancfg\n"
        << "Lanzou Cloud https://bjea.lanzoup.com/csgocfg\n"
        << "Bilibili     https://space.bilibili.com/412625865\n";
}

void Auto() {
    system("cls");
    std::map<std::string, std::string> log = {
        {"Release version", "v1.0"},
        {"Config version", "v1.6"}
    };

    // fetch steam path (CMD cd / & dir /s /b Steam)
    std::cout << "Fetching steam path ...\n(it might take quite long since it scans your whole disc from C:/)\n";
    if (isDebug()) {
        steam_path = Const::Path::Steam::x86;
    } else {
        std::vector<std::string> steam_paths = Bash::fetchAllSteamPaths(Const::Path::Steam::userdata);
        switch (steam_paths.size()) {
            case 0:
                throw Exceptions::Steam::kPathNotFound;
            case 1:
                steam_path = steam_paths[0];
                std::cout << "Steam path: " << steam_path << std::endl;
                break;
            default:
                steam_path = steam_paths[UI::MultiChoice("Multiple steam paths were detected.\nYou have to choose one of them.", steam_paths)];
        }
    }
    log["Steam"] = steam_path;

    // fetch user code (CMD cd steampath/userdata & dir /b)
    std::vector<std::string> user_codes = Bash::fetchAllUsers();

    // fetch user nickname (<steam_path>\userdata\<usercode>\config\localconfig.vdf, find \"PersonaName\"\t\t\", index(last char) + 1 as POS, to find_first_of('\"', POS))
    // store all code with nicknames
    std::vector<std::string> users = {};
    for (auto each : user_codes) {
        users.push_back("[" + each + "] " + File::fetchUserNickname(each));
    }
    int user_index;
    // ask user to make a choice of account
    switch (users.size()) {
        case 0:
            throw Exceptions::Steam::kUserNotFound;
        case 1:
            user_index = 0;
            std::cout << "User: " << users[0] << std::endl;
            break;
        default:
            user_index = UI::MultiChoice("Multiple users were detected.\nYou have to choose one of them.", users);
    }
    user_code = user_codes[user_index];
    log["User"] = users[user_index];

    // fetch all config from <steam_path>\userdata\<usercode>\730\local\cfg\config.cfg
    // parse and store in unordered map
    // debug info
    system("cls");
    debug_info << steam_path << std::endl << user_code; ddump();
    Config::General::Init();
    debug_info << "breakpoint 001"; ddump();
    Config::General::Auto();
    debug_info << "breakpoint 002"; ddump();

    // fetch output path <steam_path>\steamapps\common\Counter-Strike Global Offensive\csgo\cfg
    std::string cfg_path = Const::Path::GameCfg();
    if (isDebug()) {
        steam_path = Const::Path::Steam::x86;
    } else if (!Bash::isPathExist(cfg_path)) {
        std::vector<std::string> steam_paths = Bash::fetchAllSteamPaths(Const::Path::Steam::userdata);
        switch (steam_paths.size()) {
            case 0:
                throw Exceptions::Steam::kPathNotFound;
            case 1:
                steam_path = steam_paths[0];
                std::cout << "Steam path: " << steam_path << std::endl;
                break;
            default:
                steam_path = steam_paths[UI::MultiChoice("Multiple CS:GO steam paths were detected.\nYou have to choose one of them.", steam_paths)];
        }
        cfg_path = Const::Path::GameCfg();
    }
    log["Game config"] = cfg_path;

    // check if cfg\wumiancfg exist, if so, ask user to confirm (overwrite)
    // if not, CMD mkdir wumiancfg
    log["First time"] = "true";
    if (Bash::isPathExist(Const::Path::Package())) {
        log["First time"] = "false (with 1 backup generated)";
        if (UI::MultiChoice("You already have a version of wumiancfg-csgo.\nDo you want to overwrite (with a backup)?", {"No, i don't. (exit)", "Yes, please! (backup & continue)"}) == 0) {
            system("cls");
            std::cout << "Aborted (user option).\n";
            return;
        }
    }

    // fetch the latest backup config in cfg\wumiancfg\backups\ with (CMD dir /b)
    // add a new backup to cfg\wumiancfg\backups\ from <steam_path>\userdata\<usercode>\730\local\cfg\config.cfg with (CMD xcopy /E/I/H/Y <from> <to>)
    Bash::newBackup(Bash::isPathExist(Const::Path::Backups()) ? (Bash::fetchLatestBackup() + 1) % 1145 : 0);

    // generate new config files using the config read previously
    File::Write(Config::General::getBuffer());

    // read cfg\autoexec.cfg, check if 'exec "wumiancfg/default"' exists
    // if not, add to the next line from the end of autoexec.cfg
    Bash::modifyAutoExec();

    // inform user that everything is done
    system("cls");
    std::cout << "Congrats! Everything went well~\n";
    // provide possible log and print to screen (also ask if file requires)
    debug_info << "log outside 001"; ddump();
    File::Log(log);
    debug_info << "log outside 002"; ddump();
    system("pause");
}

}