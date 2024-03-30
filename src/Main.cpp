#include <iostream>
#include "TestOptions.h"

void printHelp() {
    std::cout << "Usage: [option] [arguments]\n"
              << "Options:\n"
              << "  -p [password]       Set the password.\n"
              << "  -h                  Display Help"
              << "  all                 Run all tests.\n";
}

template<typename Func>
void registerCommand(std::unordered_map<std::string, std::function<void()>>& commandMap, const std::string& command, Func func) {
    commandMap[command] = func;
}

int main(int argc, char* argv[]) {

    TestOptions test;
    std::unordered_map<std::string, std::function<void()>> commandMap;

    registerCommand(commandMap, "-h", [&]() { printHelp(); });
    //registerCommand(commandMap, "all", [&]() { test.testAll(); });

    if (argc == 1) {
        printHelp();
        return 0; 
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        if (arg == "-p") {
            if (++i < argc) {
                test.setPassword(argv[i], 0);
                continue;
            } else {
                std::cout << "Password was not specified.\n";
                break;
            }
        }

        auto cmdIt = commandMap.find(arg);
        if (cmdIt != commandMap.end()) {
            test.setup();
            cmdIt->second(); // Execute the command
        } else {
            std::cout << "No Argument Matches '" << arg << "'.\n";
            printHelp();
            break;
        }
    }
    return 0;
}
