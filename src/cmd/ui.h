#ifndef _UI_H_
#define _UI_H_

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include "exceptions.h"

namespace UI {
    int MultiChoice(std::string display, const std::vector<std::string>& options);
}

#endif