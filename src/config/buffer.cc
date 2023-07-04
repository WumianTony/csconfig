#include "config.h"

namespace Config {
    
// the function below will be optimize in the next large version
std::unordered_map<std::string, std::stringstream> General::getBuffer() {
std::unordered_map<std::string, std::stringstream> buffer;
// default.cfg
buffer["default.cfg"]
<< "// 本 CFG 配置文件由 Wumian_Tony 编写，版本 v1.6\n"
<< "clear\n"
<< "echo \"正在加载 Wumian_Tony 的配置 (v1.6)\"\n"
<< "echo \"\"\n"
<< "\n"
<< "exec wumiancfg-csgo/user/args     // 导入用户的 CFG 参数\n"
<< "exec wumiancfg-csgo/user/binds    // 导入用户绑定的键位\n"
<< "exec wumiancfg-csgo/user/commands // 导入指令\n"
<< "\n"
<< "// 加载结束\n"
<< "echo \"配置已加载完毕，以下是帮助内容\"\n"
<< "echo \"\"\n"
<< "exec wumiancfg-csgo/help\n";
// help.cfg
buffer["help.cfg"]
<< "echo \"【特殊按键】\"\n"
<< "echo \"可以去 wumiancfg-csgo/user/binds.cfg 修改\"\n"
<< "echo \"\"\n"
<< "echo \"按键 | 功能\"\n"
<< "echo \"----|-----------------------------------------------------\"\n"
<< "echo \"  ` | 打开控制台\"\n"
// << "echo \"  Q | 一键跳投\"\n"
// << "echo \"滚轮 | 跳跃（默认空格滚轮都可跳）\"\n"
<< "echo \"道具 | 切换道具，同时切换道具准星；切换其他物品恢复\"\n"
// << "echo \"  L | 切换左右手持枪\"\n"
// << "echo \"  V | 切换狙击镜准星（停稳后）是否透明，切换屏幕白度\"\n"
<< "echo \"Caps| （跑图模式）穿墙飞行\"\n"
<< "echo \"  8 | （跑图模式）重复上一投掷物\"\n"
<< "echo \"  9 | （跑图模式）清除烟雾弹及其效果\"\n"
<< "echo \"  0 | （跑图模式）放置一个 Bot\"\n"
<< "echo \"  - | （跑图模式）踢出所有 Bot\"\n"
<< "echo \"  + | （跑图模式）加入一组“AK/M4/大狙优先”专家人机\"\n"
<< "echo \"----|-----------------------------------------------------\"\n"
<< "\n"
<< "echo \"\"\n"
<< "\n"
<< "echo \"【指令列表 | 公共服务器】\"\n"
<< "echo \"可以去 wumiancfg-csgo/user/commands.cfg 修改\"\n"
<< "echo \"\"\n"
<< "echo \"指令        | 功能\"\n"
<< "echo \"-----------|----------------------------------------------\"\n"
<< "echo \"recfg      | 重载本配置，清屏并显示【按键列表】与【指令列表】\"\n"
<< "echo \"cfghelp    | 显示【按键列表】与【指令列表】\"\n"
<< "echo \"bug_molly  | 【提示】功能已停用，等待下次翻新\"\n"
<< "echo \"call_anubis| 【提示】功能已停用，等待下次翻新\"\n"
<< "echo \"scam       | 发送一条 Rick Roll 诈骗信息\"\n"
<< "echo \"-----------|----------------------------------------------\"\n"
// << "echo \"gyro_on/off| 启用/禁用 假转（慎用！有人被 OW 封禁）\"\n"
// << "echo \"-----------|----------------------------------------------\"\n"
<< "\n"
<< "echo \"\"\n"
<< "\n"
<< "echo \"【指令列表 | 个人服务器】\"\n"
<< "echo \"可以去 wumiancfg-csgo/user/commands.cfg 修改\"\n"
<< "echo \"\"\n"
<< "echo \"指令          | 功能\"\n"
<< "echo \"-------------|--------------------------------------------\"\n"
<< "echo \"projectile   | 重置为跑图模式\"\n"
<< "echo \"clutch       | 重置为残局模式\"\n"
<< "echo \"-------------|--------------------------------------------\"\n"
<< "echo \"bhop_on/off  | 启用/禁用 空格自动连跳\"\n"
<< "echo \"xray_on/off  | 启用/禁用 生物模型隔墙显示\"\n"
<< "echo \"radar_on/off | 启用/禁用 雷达全局显示\"\n"
<< "echo \"lock_on/off  | 启用/禁用 机器人锁头\"\n"
<< "echo \"nrcl_on/off  | 启用/禁用 跑打无扩散 + 弹道无后座\"\n"
<< "echo \"hspd_on/off  | 启用/禁用 高速移动\"\n"
<< "echo \"hitbox_on/off| 启用/禁用 地形碰撞显示\"\n"
<< "echo \"knife_on/off | 启用/禁用 爪刀\"\n"
<< "echo \"-------------|--------------------------------------------\"\n"
<< "\n"
<< "echo \"【指令列表 | 开发者】\"\n"
<< "echo \"\"\n"
<< "echo \"指令               | 功能\"\n"
<< "echo \"------------------|---------------------------------------\"\n"
<< "echo \"cvarlist          | 显示所有参数\"\n"
<< "echo \"cvarlist a        | 显示所有A开头的参数\"\n"
<< "echo \"help <var>        | 查看某个参数的具体帮助\"\n"
<< "echo \"key_listboundkeys | 查看所有绑定的键位\"\n"
<< "echo \"------------------|---------------------------------------\"\n";
// # hack
// - antibhop.cfg
buffer["hack\\antibhop.cfg"]
<< "sv_cheats 1\n"
<< "sv_airaccelerate 12\n"
<< "sv_enablebunnyhopping 0\n"
<< "sv_autobunnyhopping 0\n"
<< "echo \"禁用 空格自动连跳\"\n";
// // - antigyro.cfg
// buffer["hack\\antigyro.cfg"];
// << Bind::default_[Bind::default_i[Bind::default_anti["+util_left"]]].to_str() + "\n"
// << "echo \"禁用 控制台假转\"\n";
// - antilock.cfg
buffer["hack\\antilock.cfg"]
<< "sv_cheats 1\n"
<< "ent_fire cs_bot addoutput \"ModelScale 1\"\n"
<< "echo \"禁用 机器人锁头\"\n";
// - antixray.cfg
buffer["hack\\antixray.cfg"]
<< "sv_cheats 1\n"
<< "r_drawothermodels 1\n"
<< "echo \"启用 生物模型隔墙显示\"\n";
// - bunnyhop.cfg
buffer["hack\\bunnyhop.cfg"]
<< "sv_cheats 1\n"
<< "sv_airaccelerate 20000000000\n"
<< "sv_enablebunnyhopping 1\n"
<< "sv_autobunnyhopping 1\n"
<< "echo \"启用 空格自动连跳\"\n";
// - enable-recoil.cfg
buffer["hack\\enable-recoil.cfg"]
<< "sv_cheats 1\n"
<< "weapon_accuracy_nospread 0\n"
<< "weapon_recoil_scale 2\n"
<< "echo \"禁用 弹道无后座\"\n"
<< "echo \"禁用 跑打无扩散\"\n";
// // - gyro.cfg
// buffer["hack\\gyro.cfg"];
// << "alias +gyro \"+util_left;sensitivity 0.90001;m_yaw 2000\"\n"
// << "alias -gyro \"-util_left;sensitivity 4.14;m_yaw 0.022\"\n"
// << "bind " + Bind::default_[Bind::default_i[Bind::default_anti["+util_left"]]].key + " +gyro\n"
// << "echo \"启用 控制台假转\"\n";
// - high-speed.cfg
buffer["hack\\high-speed.cfg"]
<< "sv_cheats 1\n"
<< "ent_create player_speedmod\n"
<< "ent_fire player_speedmod ModifySpeed 3\n"
<< "echo \"启用 高速移动\"\n";
// - hitbox.cfg
buffer["hack\\hitbox.cfg"]
<< "r_drawclipbrushes 2\n"
<< "echo \"启用 地图碰撞箱\"\n";
// - knife.cfg
buffer["hack\\knife.cfg"]
<< "sv_cheats 1\n"
<< "mp_drop_knife_enable 1\n"
<< "give weapon_knife_karambit\n"
<< "ent_fire weapon_knife addoutput \"classname weapon_knifegg\"\n"
<< "echo \"发了一把爪子刀\"\n";
// - lock.cfg
buffer["hack\\lock.cfg"]
<< "sv_cheats 1\n"
<< "ent_fire cs_bot addoutput \"ModelScale 0\"\n"
<< "echo \"启用 机器人锁头\"\n";
// - low-speed.cfg
buffer["hack\\low-speed.cfg"]
<< "sv_cheats 1\n"
<< "ent_create player_speedmod\n"
<< "ent_fire player_speedmod ModifySpeed 1\n"
<< "echo \"禁用 高速移动\"\n";
// - no-hitbox.cfg
buffer["hack\\no-hitbox.cfg"]
<< "r_drawclipbrushes 0\n"
<< "echo \"禁用 地图碰撞箱\"\n";
// - no-knife.cfg
buffer["hack\\no-knife.cfg"]
<< "give weapon_knife_t\n"
<< "give weapon_knife\n"
<< "echo \"禁用特殊刀型\"\n";
// - no-radar.cfg
buffer["hack\\no-radar.cfg"]
<< "mp_radar_showall 0\n"
<< "echo \"禁用 雷达全局显示\"\n";
// - norecoil.cfg
buffer["hack\\norecoil.cfg"]
<< "sv_cheats 1\n"
<< "weapon_accuracy_nospread 1\n"
<< "weapon_recoil_scale 0\n"
<< "echo \"启用 弹道无后座\"\n"
<< "echo \"启用 跑打无扩散\"\n";
// - radar.cfg
buffer["hack\\radar.cfg"]
<< "sv_cheats 1\n"
<< "mp_radar_showall 1\n"
<< "echo \"启用 雷达全局显示\"\n";
// - xray.cfg
buffer["hack\\xray.cfg"]
<< "sv_cheats 1\n"
<< "r_drawothermodels 2\n"
<< "echo \"启用 生物模型隔墙显示\"\n";
// # call
// - scam.cfg
buffer["call\\scam.cfg"]
<< "say \"我们的战队正在和 G2 Esports 进行比赛，请为我们投上一票：985.so/bragk\"\n"
<< "say \"We're currently competing with G2 Esports, pls vote for us. Link: 985.so/bragk\"\n";
// # training
// - hell.cfg
buffer["training\\hell.cfg"]
<< "mp_warmup_end\n"
<< "ammo_grenade_limit_total 6\n"
<< "mp_autoteambalance 0\n"
<< "mp_maxmoney 65535\n"
<< "mp_startmoney 65535\n"
<< "\n"
<< "mp_limitteams 0\n"
<< "mp_autokick 0\n"
<< "mp_friendlyfire 0\n"
<< "\n"
<< "mp_restartgame 1\n"
<< "\n"
<< "echo \"已刷新为全经济模式\"\n";
// - projectile.cfg
buffer["training\\projectile.cfg"]
<< "mp_warmup_end\n"
<< "\n"
<< "sv_cheats 1\n"
<< "sv_infinite_ammo 1\n"
<< "sv_showimpacts 1\n"
<< "sv_grenade_trajectory 1\n"
<< "sv_grenade_trajectory_time 20\n"
<< "\n"
<< "gods 1\n"
<< "\n"
<< "ammo_grenade_limit_total 6\n"
<< "\n"
<< "mp_roundtime_defuse 60\n"
<< "mp_maxmoney 65535\n"
<< "mp_startmoney 65535\n"
<< "mp_buy_anywhere 1\n"
<< "mp_buytime 3600\n"
<< "mp_freezetime 0\n"
<< "mp_autoteambalance 0\n"
<< "mp_limitteams 0\n"
<< "mp_autokick 0\n"
<< "mp_friendlyfire 0\n"
<< "\n"
<< "bot_stop 1\n"
<< "bot_dont_shoot 1\n"
<< "bot_freeze 1\n"
<< "\n"
<< "mp_restartgame 1\n"
<< "\n"
<< "echo \"已刷新为跑图模式\"\n";
// # user
// - args.cfg
for (auto each : Arg::default_) { 
    buffer["user\\args.cfg"] << each.to_str() << "\n";
}
// - binds.cfg
for (auto each : Alias::user_) {
    buffer["user\\binds.cfg"] << each.to_str() << "\n";
}
for (auto each : Bind::default_) {
    buffer["user\\binds.cfg"] << each.to_str() << "\n";
}
// alias
for (auto each : Alias::cmd_) {
    buffer["user\\commands.cfg"] << each.to_str() << "\n";
}

return buffer;
}
}