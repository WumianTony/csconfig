#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "global.h"

namespace Config {
    typedef std::unordered_map<std::string, int> Index;
    struct Arg {
        std::string name;
        std::string value;
    };
    struct Toggle {
        std::string arg_name;
        std::string from;
        std::string to;
    };
    struct Commands {
        std::vector<std::string> commands; // 0
        std::vector<Arg> args;             // 1
        std::vector<Toggle> toggles;       // 2
    };
    struct Bind {
        std::string key;
        Commands command_serial;
    };
    struct Alias {
        std::string name;
        Commands command_serial;
    };

    static std::vector<Arg> user_args;
    static Index user_args_index;
    static std::vector<Arg> default_args;
    static Index default_args_index;

    static std::vector<Bind> user_binds;
    static Index user_binds_index;
    static std::vector<Bind> default_binds;
    static Index default_binds_index;

    static std::vector<Alias> aliases;
    static Index aliases_index;

    void Init();
    void Parse(std::string raw_config);
    std::string Serialize(Commands command_serial);

    namespace Generate {
        Index index(std::vector<Arg> args);
        Index index(std::vector<Bind> binds);
        Index index(std::vector<Alias> aliases);
        Index antimap(std::vector<Bind> binds);

        namespace Args {
            std::vector<Arg> Default();
        }

        namespace Binds {
            std::vector<Bind> Default();
        }

        namespace Aliases {
            std::vector<Alias> Default();
            void CustomCommands(std::vector<Alias>& aliases);
        }
    }

    namespace Fetch {
        Arg arg(std::string name);
        Bind bind(std::string key);
        Bind antibind(std::string target); // either command or arg_name
    }
}

#endif