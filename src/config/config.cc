#include "config.h"

namespace Config {

std::vector<Arg> Arg::user_;
Index Arg::user_i;
std::vector<Bind> Bind::user_;
Index Bind::user_i;
Antimap Bind::user_anti;
Index Alias::user_i;
std::vector<std::string> General::user_ignore;

void General::Init() {
    File::Read(Const::Path::UserCfg(), General::Parse);
    General::UserMap();
    Alias::Load();
    Alias::user_i = Alias::index(Alias::user_);
}

void General::UserMap() {
    Arg::user_i = Arg::index(Arg::user_);
    Bind::user_i = Bind::index(Bind::user_);
    Bind::user_anti = Bind::antimap(Bind::user_);
}

Arg Arg::_parse(std::string temp) {
    size_t space = temp.find_first_of(' ');
    debug_info << "_parseArg() " << temp.substr(0 , space) << "|" << temp.substr(space + 1); ddump();
    return {
        temp.substr(0, space),
        temp.substr(space + 1)
    };
}

Toggle Toggle::_parse(std::string temp) {
    size_t space_first = temp.find_first_of(' ');
    size_t space_second = temp.find_first_of(' ', space_first + 1);
    size_t space_third = temp.find_first_of(' ', space_second + 1);
    debug_info << "_parseToggle() " << temp.substr(space_first + 1, space_second - space_first - 1) << "|" << temp.substr(space_second + 1, space_third - space_second - 1) << "|" << temp.substr(space_third + 1); ddump();
    return {
        temp.substr(space_first + 1, space_second - space_first - 1),
        temp.substr(space_second + 1, space_third - space_second - 1),
        temp.substr(space_third + 1)
    };
}

Commands Commands::parse(std::string raw_command) {
    const std::regex sub_arg("^[^ ]+ [0-9.]+$");
    const std::regex sub_toggle("^toggle [^ ]+ [^ ]+ [^ ]+$");
    std::stringstream ss(raw_command);
    std::string temp;
    Commands command_serial;
    while (std::getline(ss, temp, ';')) {
        size_t start = temp.find_first_not_of(' ');
        size_t end = temp.find_last_not_of(' ');
        temp = temp.substr(start, end - start + 1);
        if (std::regex_match(temp, sub_toggle)) {
            command_serial.toggles.push_back(Toggle::_parse(temp));
        } else if (std::regex_match(temp, sub_arg)) {
            command_serial.args.push_back(Arg::_parse(temp));
        } else {
            command_serial.commands.push_back(temp);
        }
    }
    return command_serial;
}

Arg Arg::parse(std::string raw_cfg_line) {
    size_t quote = raw_cfg_line.find_first_of('\"');
    debug_info << "parseArg() " << raw_cfg_line.substr(0, quote - 1) << "|" << raw_cfg_line.substr(quote + 1, raw_cfg_line.size() - quote - 2); ddump();
    return {
        raw_cfg_line.substr(0, quote - 1),
        raw_cfg_line.substr(quote + 1)
    };
}

Bind Bind::parse(std::string raw_cfg_line) {
    size_t quote_first = raw_cfg_line.find_first_of('\"');
    size_t quote_second = raw_cfg_line.find_first_of('\"', quote_first + 1);
    std::string key = raw_cfg_line.substr(quote_first + 1, quote_second - quote_first - 1);
    debug_info << "parseBind() " << key << "|" << raw_cfg_line.substr(quote_second + 3); ddump();
    Commands command_serial = Commands::parse(raw_cfg_line.substr(quote_second + 3, raw_cfg_line.size() - quote_second - 4));
    return {key, command_serial};
}

void General::Parse(std::string raw_cfg_line) {
    const std::regex arg_pattern("^[^\" ]+ \"[^\"]*\"$");
    const std::regex bind_pattern("^bind \"[^\"]+\" \"[^\"]+\"$");
    if (std::regex_match(raw_cfg_line, arg_pattern)) {
        Arg::user_.push_back(Arg::parse(raw_cfg_line));
    } else if (std::regex_match(raw_cfg_line, bind_pattern)) {
        Bind::user_.push_back(Bind::parse(raw_cfg_line));
    } else {
        user_ignore.push_back(raw_cfg_line);
    }
}

std::string Arg::_to_str() {
    return this->name + ' ' + this->value;
}

std::string Arg::to_str() {
    return this->name + " \"" + this->value + "\"";
}

std::string Toggle::_to_str() {
    return "toggle " + this->arg_name + " " + this->from + " " + this->to;
}

std::string Commands::to_str() {
    std::vector<std::string> buffer;
    for (auto each : this->commands) buffer.push_back(each);
    for (auto each : this->args) buffer.push_back(each._to_str());
    for (auto each : this->toggles) buffer.push_back(each._to_str());
    std::string result = buffer[0];
    for (int i = 1; i < buffer.size(); i ++) result += "; " + buffer[i];
    return result;
}

std::string Bind::to_str() {
    return "bind \"" + this->key + "\" \"" + this->command_serial.to_str() + "\"";
}

std::string Alias::to_str() {
    return "alias \"" + this->name + "\" \"" + this->command_serial.to_str() + "\"";
}

std::unordered_map<std::string, std::stringstream> General::getBuffer() {
    std::unordered_map<std::string, std::stringstream> buffer;
    
    buffer["user\\args.cfg"];

    return buffer;
}
}