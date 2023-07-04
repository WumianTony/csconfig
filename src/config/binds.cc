#include "config.h"

namespace Config {

std::vector<Bind> Bind::default_ = {
    // item
    {"1", {{"slot1", "std_crosshair"}, {}, {}}},
    {"2", {{"slot2", "std_crosshair"}, {}, {}}},
    {"3", {{"slot3", "std_crosshair"}, {}, {}}},
    {"5", {{"slot5", "std_crosshair"}, {}, {}}},
    {"f4", {{"slot12", "std_crosshair"}, {}, {}}},
    // {"capslock", {{"lastinv", "std_crosshair"}, {}, {}}},
    {"mouse1", {{"+util_left"}, {}, {}}},
    {"mouse2", {{"+util_right"}, {}, {}}},
    {"4", {{"slot4", "util_crosshair"}, {}, {}}},
    {"v", {{
        "use weapon_knife", 
        "use weapon_flashbang", 
        "util_crosshair"
    }, {}, {}}},
    {"c", {{
        "use weapon_knife", 
        "use weapon_smokegrenade", 
        "util_crosshair"
    }, {}, {}}},
    {"x", {{
        "use weapon_knife", 
        "use weapon_molotov",
        "use weapon_incgrenade", 
        "util_crosshair"
    }, {}, {}}},
    // // special features
    // {"mwheelup", {{"+jump"}, {}, {}}},
    // {"mwheeldown", {{"+jump"}, {}, {}}},
    // {"q", {{"+jump", "-attack", "-attack2", "-jump"}, {}, {}}},
    // {"v", {{}, {}, {
    //     {"cl_crosshair_sniper_show_normal_inaccuracy", "1", "0"}, {"mat_monitorgamma", "1.6", "2.0"}
    // }}},
    // {"l", {{}, {}, {{"cl_righthand", "0", "1"}}}},
    // // move
    // {"w", {{"+forward"}, {}, {}}},
    // {"s", {{"+back"}, {}, {}}},
    // {"a", {{"+moveleft"}, {}, {}}},
    // {"d", {{"+moveright"}, {}, {}}},
    // {"space", {{"+jump"}, {}, {}}},
    // {"shift", {{"+speed"}, {}, {}}},
    // {"ctrl", {{"+duck"}, {}, {}}},
    // // interact
    // {"b", {{"buymenu"}, {}, {}}},
    // {"e", {{"+use"}, {}, {}}},
    // {"f", {{"+lookatweapon"}, {}, {}}},
    // {"g", {{"drop"}, {}, {}}},
    // {"r", {{"+reload"}, {}, {}}},
    // {"escape", {{"cancelselect"}, {}, {}}},
    // {"mouse3", {{"player_ping"}, {}, {}}},
    // // menus
    // {"m", {{"teammenu"}, {}, {}}},
    // {"p", {{"+spray_menu"}, {}, {}}},
    // {"`", {{"toggleconsole"}, {}, {}}},
    // {"tab", {{"+showscores"}, {}, {}}},
    // // communication
    // {"k", {{"+voicerecord"}, {}, {}}},
    // {"t", {{"messagemode"}, {}, {}}},
    // {"y", {{"messagemode2"}, {}, {}}},
    // {"u", {{"radio"}, {}, {}}},
    // {"del", {{}, {}, {{"mute", "0", "1"}}}},
    // // other
    // {"pause", {{"pause"}, {}, {}}},
    // {"f3", {{"askconnect_accept"}, {}, {}}},
    // {"f5", {{"jpeg"}, {}, {}}},
    // {"f6", {{"save quick"}, {}, {}}},
    // {"f7", {{"load quick"}, {}, {}}},
    // {"f10", {{"quit prompt"}, {}, {}}},
    // projectile server
    {"capslock", {{"+noclip"}, {}, {}}},
    {"8", {{"sv_rethrow_last_grenade"}, {}, {}}},
    {"9", {{
        "ent_fire smokegrenade_projectile kill", 
        "record abc.abc", "stop"
    }, {}, {}}},
    {"0", {{"bot_place"}, {}, {}}},
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

// slot1 slot2 slot3 slot5 slot12 lastinv -> & std_crosshair
// +attack -> +util_left
// +attack2 -> +util_right
// slot4 -> & util_crosshair
const std::string _std_crosshair[] = {
    "slot1", "slot2", "slot3", "slot4", "slot5", "slot12",
    // "slot6", "slot7", "slot8", "slot9", "slot10", "slot11", "lastinv", 
    "use weapon_flashbang", "use weapon_smokegrenade",
    "use weapon_molotov", "use weapon_incgrenade"
}; // double fire, should be fixed with a better logic in the future
void Bind::Auto() {
    debug_info << "autobind 001"; ddump();
    for (auto each : _std_crosshair) {
        debug_info << "autobind 002 " << each; ddump();
        if (user_anti.count(each)) {
            debug_info << "autobind 003"; ddump();
            default_[default_i[default_anti[each][0]]].key
                = user_anti[each][0];
            default_anti[each][0] = user_anti[each][0];
        }
    }
    debug_info << "autobind 004 " << user_anti.count("+attack"); ddump();
    std::string key_first = "mouse1";
    if (user_anti.count("+util_left")) 
        key_first = user_anti["+util_left"][0];
    else if (user_anti.count("+attack")) 
        key_first = user_anti["+attack"][0];
    default_[default_i[default_anti["+util_left"][0]]].key = key_first;
    default_anti["+util_left"][0] = key_first;

    debug_info << "autobind 005"; ddump();
    std::string key_second = "mouse2";
    if (user_anti.count("+util_right")) 
        key_second = user_anti["+util_right"][0];
    else if (user_anti.count("+attack2")) 
        key_second = user_anti["+attack2"][0];
    default_[default_i[default_anti["+util_right"][0]]].key = key_second;
    default_anti["+util_right"][0] = key_second;
    debug_info << "autobind 006"; ddump();
}

}
