#ifndef _GLOBAL_H_
#define _GLOBAL_H_
// c
#include <conio.h>
#include <windows.h>
// cpp
#include <iostream>
#include <codecvt>
#include <cstring>
#include <fstream>
#include <locale>
#include <regex>
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>
#include <unordered_map>

extern bool debug_mode;
extern std::stringstream debug_info;
void dclear();
void ddump();
bool isDebug();

// cmd
#include "bash.h"
#include "ui.h"
// config
#include "config.h"
// constant
#include "const.h"
#include "exceptions.h"
// control
#include "ctrl.h"
extern std::string steam_path, user_code;
// other
#include "fileio.h"

#endif