//
// Created by wnuke on 2020-10-16.
//

#include <iostream>
#include "CLI.h"

void CLI::prompt() {
    printf("hl-mc-cpp > ");
}

void CLI::loop() {
    while (std::cin) {
        prompt();
        std::string commandString;
        getline(std::cin, commandString);
        for (auto & i : commands) {
            if (i.matches(commandString)) {
                i.run();
            }
        }
    }
}

void CLI::setup() {
    commands.emplace_back("test", "Test command.");
    commands.emplace_back("hi", "Hello!");
    loop();
}

void CLI::run(std::string name) {

}
