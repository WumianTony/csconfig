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

Index antimap(std::vector<Bind> binds) {
    Index binds_antimap = {};
    for (auto bind : binds) {
        for (auto command : bind.command_serial.commands) {
            binds_antimap[command] = bind.key;
        }
        for (auto arg : bind.command_serial.args) {
            binds_antimap[arg.name] = bind.key;
        }
        for (auto toggle : bind.command_serial.toggles) {
            binds_antimap[toggle.arg_name] = bind.key;
        }
    }
    return binds_antimap;
}

namespace Binds {

}
}
}