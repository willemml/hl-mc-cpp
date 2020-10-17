//
// Created by wnuke on 2020-10-17.
//

#include "Command.h"

bool Command::matches(const std::string& string) {
    return name.rfind(string, 0) == 0;
}

Command::Command(const std::string &name, void runs(std::list<std::string> args)) {
    this->name = name;
    this->runs = runs;
}
