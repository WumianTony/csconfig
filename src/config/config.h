#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "global.h"

namespace Config {

typedef std::unordered_map<std::string, int> Index;
typedef std::unordered_map<std::string, std::vector<std::string>> Antimap;

class Arg {
public: 
    std::string name;
    std::string value;

    static std::vector<Arg> user_;
    static Index user_i;
    static std::vector<Arg> default_;
    static Index default_i;

    std::string _to_str();
    std::string to_str();

    static Arg _parse(std::string temp);
    static Arg parse(std::string temp);
    static Index index(std::vector<Arg> args);
    static Arg fetch(std::string name);

    static void Auto();
};

class Toggle {
public:
    std::string arg_name;
    std::string from;
    std::string to;

    std::string _to_str();
    static Toggle _parse(std::string temp);
};

class Commands {
public:
    std::vector<std::string> commands; // 0
    std::vector<Arg> args;             // 1
    std::vector<Toggle> toggles;       // 2

    std::string to_str();
    static Commands parse(std::string temp);
};

class Bind {
public:
    std::string key;
    Commands command_serial;

    static std::vector<Bind> user_;
    static Index user_i;
    static Antimap user_anti;
    static std::vector<Bind> default_;
    static Index default_i;
    static Antimap default_anti;

    std::string to_str();

    static Bind parse(std::string temp);
    static Index index(std::vector<Bind> binds);
    static Antimap antimap(std::vector<Bind> binds);
    static Bind fetch(std::string key);
    static std::vector<Bind> antifetch(std::string target);
    // either command or arg_name, possible with multiple results
    static std::vector<Bind> Default();

    static void Auto();
};

class Alias {
public:
    std::string name;
    Commands command_serial;

    static std::vector<Alias> user_;
    static Index user_i;
    static std::vector<Alias> cmd_;
    static Index cmd_i;

    std::string to_str();
    // static Alias parse(std::string temp);
    static Index index(std::vector<Alias> aliases);

    // static std::vector<Alias> Default();
    static void CustomCommands();
    static void Auto();

    // static Alias gyro();
    // static Alias _gyro();
    // static Alias _gyro_();
private:
    static Alias std_crosshair();
    static void std_crosshair_();
    static Alias util_crosshair();
    static Alias _util_left();
    static void _util_left_();
    static Alias _util_right();
    static void _util_right_();

};

class General {
public: 
    static std::vector<std::string> user_ignore;

    static void Init();
    static void UserMap();
    static void Parse(std::string raw_cfg_line);
    
    static void Auto();
    static std::unordered_map<std::string, std::stringstream> getBuffer();
};
}

#endif