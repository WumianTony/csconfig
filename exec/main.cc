#include <iostream>
#include <cstring>
#include <string>

#include "bash.h"
#include "ctrl.h"
#include "exceptions.h"

void COMING_SOON() {
    std::cout << "Coming Soon . . .\n";
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
    try {
        // std::cout << argc << std::endl;
        // for (int i = 0; i < argc; i ++) std::cout << argv[i] << std::endl;
        std::string 
            exe_path = Bash::Popen("cd"), 
            arg_path = std::string(argv[0]).substr(0, std::strlen(argv[0]) - 13);
        exe_path = exe_path.substr(0, exe_path.size() - 1);
        // std::cout << "#" << exe_path << "#" << arg_path << "#\n";
        if (exe_path == arg_path) { // 检测为双击打开
            system("cmd /k \"csconfig\""); // 为用户唤起阻塞的 CMD 窗口，并执行 csconfig 获取参数列表
        }

        switch (argc) {
            case 2: // single param
                if (std::string(argv[1]) == "-default") COMING_SOON();
                else if (std::string(argv[1]) == "-auto") Control::Auto();
                else if (std::string(argv[1]) == "-local") COMING_SOON();
                else if (std::string(argv[1]) == "-version") COMING_SOON();
                else if (std::string(argv[1]) == "-cfgversion") COMING_SOON();
                else paramList();
                break;

            case 3: // double params
                COMING_SOON();
                break;
                
            case 4: // triple params
                COMING_SOON();
                break;

            default: // display command list
                paramList();
                break;
        }
        // system("pause");

    } catch (Exceptions::Error error) {
        Exceptions::perr(error);
        return 1;

    } catch (std::exception& except) {
        Exceptions::Error error = Exceptions::System::kStdException;
        error.message = except.what();
        Exceptions::perr(error);
        return 1;

    } catch (...) {
        Exceptions::Error error = Exceptions::System::kUnknownError;
        Exceptions::perr(error);
        return 1;
    }
    return 0;
}