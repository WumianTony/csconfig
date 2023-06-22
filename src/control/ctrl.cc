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
    // fetch steam path, check programfiles & programfiles x86
    // if bad path, read and list all steam path and store
    // ask user to make a choice of path
    // int test = UI::MultiChoice("test\ntest", {"1", "2", "3", "114514", "1919810", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"});
    // system("cls");
    // std::cout << test;
    // return;

    std::string steam_path = "";
    // if (Bash::isPathExist(Const::Path::Steam::x86 + "/userdata")) {
    //     steam_path = Const::Path::Steam::x86;
    //     std::cout << "Steam path: " << steam_path << std::endl;
    // } else if (Bash::isPathExist(Const::Path::Steam::x64 + "/userdata")) {
    //     steam_path = Const::Path::Steam::x64;
    //     std::cout << "Steam path: " << steam_path << std::endl;
    // } else {
        // CMD dir /b Steam
        // std::cout << "Steam not found in default paths, keep fetching ...\n";
    std::cout << "Fetching steam path ...\n";
    std::vector<std::string> result = Bash::fetchAllSteamPaths();
    switch (result.size()) {
        case 0:
            throw Exceptions::Steam::kPathNotFound;
        case 1:
            steam_path = result[0];
            break;
        default:
            steam_path = result[UI::MultiChoice("Multiple steam paths were detected.\nYou have to choose one of them.", result)];
    }
    std::cout << "Steam path: " << steam_path << std::endl;
        // check each result, record if ./userdata exists (isPathExist)

    // }

    // fetch user code (CMD dir /b)
    // fetch user nickname (<steam_path>\userdata\<usercode>\config\localconfig.vdf, find \"PersonaName\"\t\t\", index(last char) + 1 as POS, to find_first_of('\"', POS))
    // store all code with nicknames
    // ask user to make a choice of account

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