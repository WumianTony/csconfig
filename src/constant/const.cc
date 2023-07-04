#include "const.h"

namespace Const {
namespace Path {

std::string UserCfg() {
    return steam_path + Steam::userdata + "\\" + user_code + Steam::localcfg;
}

std::string GameCfg() {
    return steam_path + Const::Path::Steam::csgocfg;
}

std::string Package() {
    return GameCfg() + '\\' + Const::Path::Custom::packname + '-' + Const::Path::Custom::version;
}

std::string Backups() {
    return GameCfg() + '\\' + Const::Path::Custom::packname + '-' + Const::Path::Custom::backup + '\\' + Const::Path::Custom::version;
}

}
}