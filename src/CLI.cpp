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
        std::list<std::string> args = CLI::split_string(commandString);
        if (!args.empty()) {
            if (!args.front().empty()) {
                std::string name = args.front();
                args.pop_front();
                if (!name.empty()) {
                    run(name, args);
                }
            }
        }
    }
}

void CLI::setup() {
    void (*echo)(std::list<std::string>) = [](std::list<std::string> args) {
        for (auto &i : args) {
            printf("%s\n", i.c_str());
        }
    };
    commands.emplace_back("test", echo);
    loop();
}

void CLI::run(const std::string &name, const std::list<std::string> &args) {
    for (auto &i : commands) {
        if (i.matches(name)) {
            i.runs(args);
        }
    }
}


std::list<std::string> CLI::split_string(std::string string) {
    std::list<std::string> split;
    while (true) {
        if (string.empty()) break;
        while (string.front() == ' ') string.erase(0, 1);
        bool first_is_quote = string.rfind('"', 0) == 0;
        int first_index = 0;
        if (first_is_quote) first_index = 1;
        std::string::size_type second_quote_index = string.find('"', 1);
        std::string::size_type second_space_index = string.find(' ', 1);
        int second_index;
        if (second_space_index == std::string::npos && second_quote_index == std::string::npos) {
            if (!string.empty()) split.emplace_back(string);
            break;
        }
        if (first_is_quote && second_quote_index != std::string::npos) {
            string.erase(second_quote_index, second_quote_index + 1);
            if (string.find(' ', second_quote_index + 1)) {
                second_index = second_quote_index - 1;
            } else {
                second_index = string.find(' ', second_quote_index + 1) - 1;
            }
        } else {
            second_index = second_space_index;
        }
        std::string string_found = string.substr(first_index, second_index);
        while (string_found.front() == ' ' || string_found.front() == '"') {
            string_found.erase(0, 1);
        }
        while (string_found.back() == ' ' || string_found.back() == '"') {
            string_found.pop_back();
        }
        if (!string_found.empty()) split.emplace_back(string_found);
        string.replace(0, second_index + 1, "");
    }
    return split;
}
