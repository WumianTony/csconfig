#ifndef _CONST_H_
#define _CONST_H_

#include "global.h"

namespace Const {

    namespace Path {

        namespace Steam {
            const std::string 
            x86 = "C:\\Program Files (x86)\\Steam",
            x64 = "C:\\Program Files\\Steam",
            userdata = "\\userdata",
            localcfg = "\\730\\local\\cfg\\config.cfg",
            csgocfg = "\\steamapps\\common\\Counter-Strike Global Offensive\\csgo\\cfg";
        }

        namespace Custom {
            const std::string 
            packname = "wumiancfg",
            version = "csgo",
            backup = "backups",
            directories[] = {
                "call",
                "hack",
                "training",
                "user"
            };
        }

        std::string UserCfg();
        std::string GameCfg();
        std::string Package();
        std::string Backups();
    }
}

#endif