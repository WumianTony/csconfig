#include <iostream>

void cmdlist();
int main(int argc, char* argv[]) {
    switch (argc) {
        case 2: // single param
            break;
        case 3: // double params
            break;
        default: // display command list
            cmdlist();
            break;
    }
}

void cmdlist() {
    std::cout << "\n"
              << "********* Counter Strike Config Usage *********\n"
              << "\n"
              << "                ### Setups ###\n"
              << "0.  -default                          use default setup\n"
              << "1.  -auto                             automatically choose your setup\n"
              << "\n"
              << "                ### Manual ###\n"
              << "2.  -i <input_path>                   manually setup input path (config.cfg)\n"
              << "3.  -o <output_path>                  manually setup output path (wumiancfg directory)\n"
              << "4.  -io <input_path> <output_path>    manually setup both\n"
              << "\n"
              << "                ### Others ###\n"
              << "5.  -version                          check the version of csconfig executable\n"
              << "6.  -cfgversion                       check the version of wumiancfg\n";
}