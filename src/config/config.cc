#include "config.h"

namespace Config {

void Init() {
    default_args = Generate::Args::Default();
    default_args_index = Generate::index(default_args);
    default_binds = Generate::Binds::Default();
    default_binds_index = Generate::index(default_binds);
    default_binds_antimap = Generate::antimap(default_binds);
    aliases = Generate::Aliases::Default();
    Generate::Aliases::CustomCommands(aliases);
    aliases_index = Generate::index(aliases);
}

void UserMap() {
    user_args_index = Generate::index(user_args);
    user_binds_index = Generate::index(user_binds);
    user_binds_antimap = Generate::antimap(user_binds);
}
}