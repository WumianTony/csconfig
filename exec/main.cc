#include <iostream>
#include <cstring>
#include <string>

bool getPath(std::string &path) {
    FILE *pipe = popen("cd", "r");
    if (!pipe) return true;
    char buffer[1145] = {0};
    while (fread(buffer, 1, 1144, pipe));
    if (pclose(pipe)) return true;
    path = buffer;
    return false;
}

void paramList() {
    system("cls");
    std::cout << "********* Counter Strike Config Usage *********\n"
              << "\n"
              << "                ### Setups ###\n"
              << "1.  -default                          use default path\n"
              << "2.  -auto                 (Recommend) automatically find your I/O path\n"
              << "3.  -local             (Prerequisite) only use when your steam is NOT under C:/Program Files (x86)/ or C:/Program Files/"
              << "\n"
              << "                ### Manual ###\n"
              << "1.  -i <input_path>                   manually config input path (config.cfg)\n"
              << "2.  -o <output_path>                  manually config output path (wumiancfg directory)\n"
              << "3.  -io <input_path> <output_path>    manually config both\n"
              << "\n"
              << "                ### Others ###\n"
              << "1.  -version                          check the version of csconfig executable\n"
              << "2.  -cfgversion                       check the version of wumiancfg\n";
}

int main(int argc, char* argv[]) {
    // std::cout << argc << std::endl;
    // for (int i = 0; i < argc; i ++) std::cout << argv[i] << std::endl;
    switch (argc) {
        case 2: // single param
            std::cout << "Coming Soon . . .\n";
            break;
        case 3: // double params
            std::cout << "Coming Soon . . .\n";
            break;
        default: // display command list
            std::string exe_path, arg_path = std::string(argv[0]).substr(0, std::strlen(argv[0]) - 13);
            if (getPath(exe_path)) {
                std::cerr << "Exception caught when fetching csconfig executable path\n";
                return 1;
            }
            exe_path = exe_path.substr(0, exe_path.size() - 1);
            // std::cout << "#" << exe_path << "#" << arg_path << "#\n";
            if (exe_path == arg_path) { // 检测为双击打开
                system("cmd /k \"csconfig\""); // 为用户唤起阻塞的 CMD 窗口，并执行 csconfig 获取参数列表
            } else {
                paramList();
            }
            break;
    }
    // system("pause");
    return 0;
}