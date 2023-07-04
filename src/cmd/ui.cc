#include "ui.h"

namespace UI {

static void locate(int row, int column) {
    COORD coordinates;
    coordinates.X = column;
    coordinates.Y = row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

int MultiChoice(std::string display, const std::vector<std::string>& options) {
    int index = 0;
    int amount = options.size();

    system("cls");
    std::cout << display;
    locate(3, 0);
    std::cout << "-> " << options[0] << std::endl;
    for (int i = 1; i < amount; i++) {
        std::cout << "   " << options[i] << std::endl;
    }

    while (true) {
        locate(2, 0);
        int key = _getch();
        if (key == 13) return index;
        if (key == 72 || key == 80) {
            locate(index + 3, 0);
            std::cout << "  ";
            int increment = (key == 72) ? -1 : 1; 
            index = (index + increment + amount) % amount;
            locate(index + 3, 0);
            std::cout << "->";
        }
    }
    throw Exceptions::Bash::kUIEmptyChoice;
}

}