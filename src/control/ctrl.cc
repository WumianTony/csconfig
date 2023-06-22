#include "ctrl.h"

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

    // fetch steam path (CMD cd / & dir /s /b Steam)
    std::string steam_path = "";
    std::cout << "Fetching steam path ...\n(it might take quite long since it scans your whole disc from C:/)\n";
    std::vector<std::string> steam_paths = Bash::fetchAllSteamPaths();
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

    // fetch user code (CMD cd steampath/userdata & dir /b)
    std::string user_code = "";
    std::vector<std::string> user_codes = Bash::fetchAllUsers(steam_path);

    // fetch user nickname (<steam_path>\userdata\<usercode>\config\localconfig.vdf, find \"PersonaName\"\t\t\", index(last char) + 1 as POS, to find_first_of('\"', POS))
    // store all code with nicknames
    std::vector<std::string> users = {};
    for (auto each : user_codes) {
        users.push_back("[" + each + "] " + File::fetchUserNickname(steam_path, each));
    }
    // ask user to make a choice of account
    switch (users.size()) {
        case 0:
            throw Exceptions::Steam::kUserNotFound;
        case 1:
            user_code = user_codes[0];
            std::cout << "User: " << users[0] << std::endl;
            break;
        default:
            user_code = user_codes[UI::MultiChoice("Multiple users were detected.\nYou have to choose one of them.", users)];
    }

    // debug info
    system("cls");
    std::cout << steam_path << std::endl << user_code << std::endl;

    // fetch all config from <steam_path>\userdata\<usercode>\730\local\cfg\config.cfg
    // parse and store in unordered map

    // fetch output path <steam_path>\steamapps\common\Counter-Strike Global Offensive\csgo\cfg
    // check if cfg\wumiancfg exist, if so, ask user to confirm (overwrite)
    // if not, CMD mkdir wumiancfg
    // fetch the latest backup config in cfg\wumiancfg\backups\ with (CMD dir /b)
    // add a new backup to cfg\wumiancfg\backups\ from <steam_path>\userdata\<usercode>\730\local\cfg\config.cfg with (CMD copy <from> <to>)
    
    // generate new config files using the config read previously
    // read cfg\autoexec.cfg, check if 'exec "wumiancfg/default"' exists
    // if not, add to the next line from the end of autoexec.cfg

    // inform user that everything is done
}

}