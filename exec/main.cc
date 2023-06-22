#include "global.h"

void COMING_SOON() {
    std::cout << "Coming Soon . . .\n";
}

void paramList() {
    system("cls");
    std::cout << "**************** Counter Strike Config Usage ****************\n"
              << "ALIAS   USAGE                                DESCRIPTION\n"
              << "\n"
              << "Setups\n"
              << "   -d   -default                             use default path\n"
              << "   -a   -auto                    (Recommend) automatically find your I/O path\n"
              << "   -l   -local                (Prerequisite) only use when your steam is NOT under C:/Program Files (x86)/ or C:/Program Files/\n"
              << "\n"
              << "Manual\n"
              << "   -i   -input <input_path>                  manually config input path (config.cfg)\n"
              << "   -o   -output <output_path>                manually config output path (wumiancfg directory)\n"
              << "   -io  -manual <input_path> <output_path>   manually config both\n"
              << "\n"
              << "Others\n"
              << "   -v   -version                             check the version of csconfig executable\n"
              << "   -cv  -cfgversion                          check the version of wumiancfg\n";
}

int main(int argc, char* argv[]) {
    try {
        SetConsoleOutputCP(CP_UTF8);
        // std::cout << argc << std::endl;
        // for (int i = 0; i < argc; i ++) std::cout << argv[i] << std::endl;
        std::string 
            exe_path = Bash::fetchExecPath(), 
            arg_path = std::string(argv[0]).substr(0, std::strlen(argv[0]) - 13);
        exe_path = exe_path.substr(0, exe_path.size() - 1);
        // std::cout << "#" << exe_path << "#" << arg_path << "#\n";
        if (exe_path == arg_path) { // 检测为双击打开
            system("cmd /k \"csconfig\""); // 为用户唤起阻塞的 CMD 窗口，并执行 csconfig 获取参数列表
        }

        switch (argc) {
            case 2: // single param
                if (std::string(argv[1]) == "-default" || std::string(argv[1]) == "-d") COMING_SOON();
                else if (std::string(argv[1]) == "-auto" || std::string(argv[1]) == "-a") Control::Auto();
                else if (std::string(argv[1]) == "-local" || std::string(argv[1]) == "-l") COMING_SOON();
                else if (std::string(argv[1]) == "-version" || std::string(argv[1]) == "-v") Control::Version();
                else if (std::string(argv[1]) == "-cfgversion" || std::string(argv[1]) == "-cv") Control::ConfigVersion();
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
    // system("pause");
    return 0;
}