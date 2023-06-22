#include "ctrl.h"

namespace Control {

int Auto() {
    // fetch steam path, check programfiles & programfiles x86
    // if bad path, read and list all steam path and store
    // ask user to make a choice of path

    // fetch user code (CMD dir /b)
    // fetch user nickname (<steam_path>\userdata\<usercode>\config\localconfig.vdf, find \"PersonaName\"\t\t\", index(last char) + 1 as POS, to find_first_of('\"', POS))
    // store all code with nicknames
    // ask user to make a choice of account

    // fetch all config from <steam_path>\userdata\<usercode>\730\local\cfg\config.cfg
    // parse and store in unordered map

    // fetch output path <steam_path>\steamapps\common\Counter-Strike Global Offensive\csgo\cfg
    // check if cfg\wumiancfg exist, if so, ask user to confirm (overwrite)
    // if not, CMD mkdir wumiancfg
    // fetch the latest backup config in cfg\wumiancfg\backups\ with (CMD dir /b)
    // add a new backup to cfg\wumiancfg\backups\ from <steam_path>\userdata\<usercode>\730\local\cfg\config.cfg with (CMD copy <from> <to>)
    
    // generate new config files using the config read previously
    // read cfg\autoexec.cfg, check if 'exec "wumiancfg/default"' exists
    // if not, add to the next line from the end of autoexec.cfg

    // inform user that everything is done
    return 0;
}

}