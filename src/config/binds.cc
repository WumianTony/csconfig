#include "config.h"

namespace Config {

std::vector<Bind> Bind::default_ = {
    // item
    {"1", {{"slot1", "std_crosshair"}, {}, {}}},
    {"2", {{"slot2", "std_crosshair"}, {}, {}}},
    {"3", {{"slot3", "std_crosshair"}, {}, {}}},
    {"5", {{"slot5", "std_crosshair"}, {}, {}}},
    {"f4", {{"slot12", "std_crosshair"}, {}, {}}},
    {"capslock", {{"lastinv", "std_crosshair"}, {}, {}}},
    {"mouse1", {{"+util_left"}, {}, {}}},
    {"mouse2", {{"+util_right"}, {}, {}}},
    {"4", {{"slot4", "util_crosshair"}, {}, {}}},
    // special features
    {"mwheelup", {{"+jump"}, {}, {}}},
    {"mwheeldown", {{"+jump"}, {}, {}}},
    {"q", {{"+jump", "-attack", "-attack2", "-jump"}, {}, {}}},
    {"v", {{}, {}, {
        {"cl_crosshair_sniper_show_normal_inaccuracy", "1", "0"}, {"mat_monitorgamma", "1.6", "2.0"}
    }}},
    {"l", {{}, {}, {{"cl_righthand", "0", "1"}}}},
    // move
    {"w", {{"+forward"}, {}, {}}},
    {"s", {{"+back"}, {}, {}}},
    {"a", {{"+moveleft"}, {}, {}}},
    {"d", {{"+moveright"}, {}, {}}},
    {"space", {{"+jump"}, {}, {}}},
    {"shift", {{"+speed"}, {}, {}}},
    {"ctrl", {{"+duck"}, {}, {}}},
    // interact
    {"b", {{"buymenu"}, {}, {}}},
    {"e", {{"+use"}, {}, {}}},
    {"f", {{"+lookatweapon"}, {}, {}}},
    {"g", {{"drop"}, {}, {}}},
    {"r", {{"+reload"}, {}, {}}},
    {"escape", {{"cancelselect"}, {}, {}}},
    {"mouse3", {{"player_ping"}, {}, {}}},
    // menus
    {"m", {{"teammenu"}, {}, {}}},
    {"p", {{"+spray_menu"}, {}, {}}},
    {"`", {{"toggleconsole"}, {}, {}}},
    {"tab", {{"+showscores"}, {}, {}}},
    // communication
    {"k", {{"+voicerecord"}, {}, {}}},
    {"t", {{"messagemode"}, {}, {}}},
    {"y", {{"messagemode2"}, {}, {}}},
    {"u", {{"radio"}, {}, {}}},
    {"del", {{}, {}, {{"mute", "0", "1"}}}},
    // other
    {"pause", {{"pause"}, {}, {}}},
    {"f3", {{"askconnect_accept"}, {}, {}}},
    {"f5", {{"jpeg"}, {}, {}}},
    {"f6", {{"save quick"}, {}, {}}},
    {"f7", {{"load quick"}, {}, {}}},
    {"f10", {{"quit prompt"}, {}, {}}},
    // projectile server
    {"alt", {{"+noclip"}, {}, {}}},
    {"c", {{"sv_rethrow_last_grenade"}, {}, {}}},
    {"x", {{
        "ent_fire smokegrenade_projectile kill", 
        "record abc.abc", "stop"
    }, {}, {}}},
    {"z", {{"bot_place"}, {}, {}}},
    {"-", {{"bot_kick", "bot_add"}, {}, {}}},
    {"=", {{
        "bot_add wolf", 
        "bot_add kyle", 
        "bot_add gunner", 
        "bot_add quade", 
        "bot_add vitaliy", 
        "bot_add brett", 
        "bot_add steel", 
        "bot_add cliffe", 
        "bot_add arnold"
    }, {}, {}}},
};

Index Bind::default_i = index(Bind::default_);
Antimap Bind::default_anti = antimap(Bind::default_);

Index Bind::index(std::vector<Bind> binds) {
    Index binds_index = {};
    for (int i = 0; i < binds.size(); i ++) {
        binds_index[binds[i].key] = i;
    }
    return binds_index;
}

Antimap Bind::antimap(std::vector<Bind> binds) {
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

Bind Bind::fetch(std::string key) {
    if (Bind::user_i.count(key) == 1) 
        return Bind::user_[Bind::user_i[key]];
    if (Bind::default_i.count(key) == 1) 
        return Bind::default_[Bind::default_i[key]];
    throw Exceptions::Config::kBindNotFound;
}

std::vector<Bind> Bind::antifetch(std::string target) {
    std::vector<Bind> result;
    if (Bind::user_anti.count(target) == 1) {
        for (auto each : Bind::user_anti[target]) {
            result.push_back(Bind::user_[Bind::user_i[each]]);
        }
        return result;
    }
    if (Bind::default_anti.count(target) == 1) {
        for (auto each : Bind::default_anti[target]) {
            result.push_back(Bind::default_[Bind::default_i[each]]);
        }
        return result;
    }
    throw Exceptions::Config::kBindNotFound;
}

}
