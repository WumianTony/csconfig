#include "config.h"

namespace Config {

std::vector<Arg> Arg::default_ = {
    // network
    {"cl_interp", "0.031000"},
    {"cl_interp_ratio", "1"},
    // mouse
    {"m_mouseaccel1", "0"},
    {"m_mouseaccel2", "0"},
    {"sensitivity", "4.14"},
    {"zoom_sensitivity_ratio_mouse", "1.50"},
    // user interface
    {"mat_monitorgamma", "1.6"},
    {"cl_hud_color", "9"},
    {"hud_scaling", "0.85"},
    {"cl_hud_background_alpha", "0.50"},
    // {"cl_showpos", "0"},
    {"net_graph", "1"},
    {"net_graphpos", "1"},
    {"cl_hud_radar_scale", "1"},
    {"cl_radar_scale", "0.4"},
    {"viewmodel_fov", "60"},
    // crosshair
    {"cl_crosshair_sniper_width", "2"},
    {"cl_crosshairalpha", "255"},
    {"cl_crosshairdot", "1"},
    {"cl_crosshair_t", "0"},
    {"cl_crosshairgap", "-3.0000001192092880"},
    {"cl_crosshairstyle", "4"},
    {"cl_crosshair_outlinethickness", "0"},
    {"cl_crosshair_drawoutline", "0"},
    {"cl_crosshaircolor", "4"},
    {"cl_crosshairsize", "0"},
    {"cl_crosshairthickness", "1"},
    // gun model
    {"viewmodel_recoil", "0"},
    {"cl_bob_lower_amt", "5"},
    {"cl_bobamt_lat", "0.1"},
    {"cl_bobamt_vert", "0.1"},
    // other
    {"spec_replay_autostart", "0"}
};

Index Arg::default_i = index(Arg::default_);

Index Arg::index(std::vector<Arg> args) {
    Index args_index = {};
    for (int i = 0; i < args.size(); i ++) {
        args_index[args[i].name] = i;
    }
    return args_index;
}

Arg Arg::fetch(std::string name) {
    if (Arg::user_i.count(name) == 1) 
        return Arg::user_[Arg::user_i[name]];
    if (Arg::default_i.count(name) == 1) 
        return Arg::default_[Arg::default_i[name]];
    throw Exceptions::Config::kArgNotFound;
}

void Arg::Auto() {
    for (auto& each : default_) {
        each = fetch(each.name);
    }
}
}