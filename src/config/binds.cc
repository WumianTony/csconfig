#include "config.h"

namespace Config {
namespace Generate {

Index index(std::vector<Bind> binds) {
    Index binds_index = {};
    for (int i = 0; i < binds.size(); i ++) {
        binds_index[binds[i].key] = i;
    }
    return binds_index;
}

Antimap antimap(std::vector<Bind> binds) {
    Antimap binds_antimap = {};
    for (auto bind : binds) {
        for (auto command : bind.command_serial.commands) {
            binds_antimap[command].push_back(bind.key);
        }
        for (auto arg : bind.command_serial.args) {
            binds_antimap[arg.name].push_back(bind.key);
        }
        for (auto toggle : bind.command_serial.toggles) {
            binds_antimap[toggle.arg_name].push_back(bind.key);
        }
    }
    return binds_antimap;
}

namespace Binds {

std::vector<Bind> Default() {
    
}

}
}

namespace Fetch {

Bind bind(std::string key) {
    if (user_binds_index.count(key) == 1) 
        return user_binds[user_binds_index[key]];
    if (default_binds_index.count(key) == 1) 
        return default_binds[default_binds_index[key]];
    throw Exceptions::Config::kBindNotFound;
}

std::vector<Bind> antibind(std::string target) {
    std::vector<Bind> result;
    if (user_binds_antimap.count(target) == 1) {
        for (auto each : user_binds_antimap[target]) {
            result.push_back(user_binds[user_binds_index[each]]);
        }
        return result;
    }
    if (default_binds_antimap.count(target) == 1) {
        for (auto each : default_binds_antimap[target]) {
            result.push_back(default_binds[default_binds_index[each]]);
        }
        return result;
    }
    throw Exceptions::Config::kBindNotFound;
}

}
}