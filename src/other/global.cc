#include "global.h"

bool debug_mode = false;
std::stringstream debug_info;

void dclear() {
    std::ofstream reset("debug_log.txt");
    reset.close();
}

void ddump() {
    if (debug_mode) {
        std::ofstream fout("debug_log.txt", std::ios::app);
        fout << debug_info.str() << std::endl;
        fout.close();
    }
    debug_info.str("");
}

bool isDebug() {
    return debug_mode;
}