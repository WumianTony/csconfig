#include "config.h"

namespace Config {

const Alias 

util_left = {"+util_left", {
    {"+attack"}, {
    {"cl_hud_color", "10"},
    {"cl_crosshaircolor", "0"}
}, {}}},

util_right = {"+util_right", {
    {"+attack2",
    "r_cleardecals"}, {
    {"cl_hud_color", "7"},
    {"cl_crosshaircolor", "2"}
}, {}}},

gyro = {"+gyro", {
    {"+util_left"}, {
    {"sensitivity", "0.90001"},
    {"m_yaw", "2000"}
}, {}}};

std::vector<Alias> Alias::user_ = {
    Alias::util_crosshair(),
    util_left,
    util_right,
    gyro
};

Index Alias::index(std::vector<Alias> aliases) {
    Index index = {};
    for (int i = 0; i < aliases.size(); i ++) {
        index[aliases[i].name] = i;
    }
    return index;
}

const std::string crosshair_args_name[] = {
    "cl_crosshairalpha",
    "cl_crosshairdot",
    "cl_crosshair_t",
    "cl_crosshairgap",
    "cl_crosshairstyle",
    "cl_crosshair_outlinethickness",
    "cl_crosshair_drawoutline",
    "cl_crosshaircolor",
    "cl_crosshairsize",
    "cl_crosshairthickness",
    "cl_crosshairdot"
};

Alias Alias::std_crosshair() {
    std::vector<Arg> crosshair_args;
    for (auto each : crosshair_args_name) {
        crosshair_args.push_back(Arg::fetch(each));
    }
    return {"std_crosshair", {{}, crosshair_args, {}}};
}

Alias Alias::util_crosshair() {
    std::vector<Arg> crosshair_args;
    debug_info << "util_crosshair 1"; ddump();
    for (int i = 0; i < 8; i ++) {
        debug_info << "util_crosshair 2 1"; ddump();
        std::string arg_name = crosshair_args_name[i];
        debug_info << "util_crosshair 2 2"; ddump();
        int index = Arg::default_i[arg_name];
        debug_info << "util_crosshair 2 3 " << Arg::default_.size(); ddump();
        auto arg = Arg::default_[index];
        debug_info << "util_crosshair 2 4"; ddump();
        crosshair_args.push_back(Arg::default_[Arg::default_i[crosshair_args_name[i]]]);
        debug_info << "util_crosshair 2 5"; ddump();
    }
    debug_info << "util_crosshair 3"; ddump();
    crosshair_args.push_back({crosshair_args_name[8], "1"});
    debug_info << "util_crosshair 4"; ddump();
    crosshair_args.push_back({crosshair_args_name[9], "3000"});
    debug_info << "util_crosshair 5"; ddump();
    crosshair_args.push_back({crosshair_args_name[10], "0.1"});
    debug_info << "util_crosshair 6"; ddump();
    return {"util_crosshair", {{}, crosshair_args, {}}};
}

Alias Alias::_util_left() {
    return {"-util_left", {
        {"-attack",
        "std_crosshair"}, {
        Arg::fetch("cl_hud_color")
    }, {}}};
}

Alias Alias::_util_right() {
    return {"-util_right", {
        {"-attack2",
        "std_crosshair"}, {
        Arg::fetch("cl_hud_color")
    }, {}}};
}

Alias Alias::_gyro() {
    return {"-gyro", {{
        "-util_left"
    }, {
        Arg::fetch("sensitivity"),
        {"m_yaw", "0.022"}
    }, {}}};
}

// std::vector<Alias> Alias::Default() {
//     std::vector<Alias> result;
//     debug_info << "Config::Generate::Aliases::Default 1"; ddump();
//     result.push_back(util_crosshair());
//     debug_info << "Config::Generate::Aliases::Default 2"; ddump();
//     result.push_back(util_left);
//     debug_info << "Config::Generate::Aliases::Default 3"; ddump();
//     result.push_back(util_right);
//     debug_info << "Config::Generate::Aliases::Default 4"; ddump();
//     result.push_back(gyro);
//     debug_info << "Config::Generate::Aliases::Default 5"; ddump();
//     return result;
// }

void Alias::Load() {
    Alias::user_.insert(Alias::user_.end(), {
        std_crosshair(),
        _util_left(),
        _util_right(),
        _gyro()
    });
}

const std::string unavaliable_custom_commands[] = {
    "call_anubis"
    "bug_molly"
};
const std::pair<std::string, std::string> custom_commands[] = {
    {"recfg", "default"},
    {"cfghelp", "help"},
    {"projectile", "training/projectile"},
    {"clutch", "training/clutch"},
    {"hell", "training/hell"},

    {"bhop_on", "hack/bunnyhop"},
    {"xray_on", "hack/xray"},
    {"radar_on", "hack/radar"},
    {"lock_on", "hack/lock"},
    {"gyro_on", "hack/gyro"},
    {"nrcl_on", "hack/norecoil"},
    {"hspd_on", "hack/high-speed"},
    {"hitbox_on", "hack/hitbox"},
    {"knife_on", "hack/knife"},

    {"bhop_off", "hack/antibhop"},
    {"xray_off", "hack/antixray"},
    {"radar_off", "hack/no-radar"},
    {"lock_off", "hack/antilock"},
    {"gyro_off", "hack/antigyro"},
    {"nrcl_off", "hack/enable-recoil"},
    {"hspd_off", "hack/low-speed"},
    {"hitbox_off", "hack/no-hitbox"},
    {"knife_off", "hack/no-knife"},

    {"scam", "/call/scam"}
};

void Alias::CustomCommands(std::vector<Alias>& aliases) {
    for (auto each : custom_commands) {
        aliases.push_back({each.first, {
            {"exec wumiancfg-csgo/" + each.second}, {}, {}
        }});
    }
    for (auto each : unavaliable_custom_commands) {
        aliases.push_back({each, {{"echo 'Not available'"}, {}, {}}});
    }
}

}
