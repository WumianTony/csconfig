#include "config.h"

namespace Config {
namespace Generate {

Index index(std::vector<Alias> aliases) {
    Index aliases_index = {};
    for (int i = 0; i < aliases.size(); i ++) {
        aliases_index[aliases[i].name] = i;
    }
    return aliases_index;
}

namespace Aliases {

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

Alias std_crosshair() {
    std::vector<Arg> crosshair_args;
    for (auto each : crosshair_args_name) {
        crosshair_args.push_back(Fetch::arg(each));
    }
    return {"std_crosshair", {{}, crosshair_args, {}}};
}

Alias util_crosshair() {
    std::vector<Arg> crosshair_args;
    for (int i = 0; i < 8; i ++) {
        crosshair_args.push_back(default_args[default_args_index[crosshair_args_name[i]]]);
    }
    crosshair_args.push_back({crosshair_args_name[8], "1"});
    crosshair_args.push_back({crosshair_args_name[9], "3000"});
    crosshair_args.push_back({crosshair_args_name[10], "0.1"});
    return {"util_crosshair", {{}, crosshair_args, {}}};
}

Alias util_left() {
    return {"+util_left", {{
        "+attack"
    }, {
        {"cl_hud_color", "10"},
        {"cl_crosshaircolor", "0"}
    }, {}}};
}

Alias _util_left() {
    return {"-util_left", {{
        "-attack",
        "std_crosshair"
    }, {
        Fetch::arg("cl_hud_color")
    }, {}}};
}

Alias util_right() {
    return {"+util_right", {{
        "+attack2",
        "r_cleardecals"
    }, {
        {"cl_hud_color", "7"},
        {"cl_crosshaircolor", "2"}
    }, {}}};
}

Alias _util_right() {
    return {"-util_right", {{
        "-attack2",
        "std_crosshair"
    }, {
        Fetch::arg("cl_hud_color")
    }, {}}};
}

Alias gyro() {
    return {"+gyro", {{
        "+util_left"
    }, {
        {"sensitivity", "0.90001"},
        {"m_yaw", "2000"}
    }, {}}};
}

Alias _gyro() {
    return {"-gyro", {{
        "-util_left"
    }, {
        Fetch::arg("sensitivity"),
        {"m_yaw", "0.022"}
    }, {}}};
}

std::vector<Alias> Default() {
    return {
        std_crosshair(),
        util_crosshair(),
        util_left(),
        _util_left(),
        util_right(),
        _util_right(),
        gyro(),
        _gyro()
    };
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

void CustomCommands(std::vector<Alias>& aliases) {
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
}
}