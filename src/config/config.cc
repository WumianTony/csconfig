#include "config.h"

namespace Config {

void Init() {
    default_args = Generate::Args::Default();
    default_args_index = Generate::index(default_args);
    default_binds = Generate::Binds::Default();
    default_binds_index = Generate::index(default_binds);
    aliases = Generate::Aliases::Default();
    Generate::Aliases::CustomCommands(aliases);
    aliases_index = Generate::index(aliases);
}
}