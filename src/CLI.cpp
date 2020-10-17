//
// Created by wnuke on 2020-10-16.
//

#include <iostream>
#include <sstream>
#include "CLI.h"

void CLI::prompt() {
    printf("hl-mc-cpp > ");
}

void CLI::loop() {
    while (std::cin) {
        prompt();
        std::string commandString;
        getline(std::cin, commandString);
        std::list<std::string> args;
        std::istringstream iss(commandString);
        std::string arg;
        std::string name;
        while (getline(iss, arg, ' ')) {
            if (!arg.empty()) {
                if (name.empty()) {
                    name = arg;
                } else {
                    args.push_back(arg);
                }
            }
        }
        if (!name.empty()) {
            run(name, args);
        }
    }
}

void CLI::setup() {
    commands.emplace_back("test", [](std::list<std::string> args){ for (auto & i : args) { printf("%s\n", i.c_str()); } });
    loop();
}

void CLI::run(const std::string& name, const std::list<std::string>& args) {
    for (auto & i : commands) {
        if (i.matches(name)) {
            i.runs(args);
        }
    }
}
