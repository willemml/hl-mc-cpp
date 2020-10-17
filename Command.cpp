//
// Created by wnuke on 2020-10-16.
//

#include "Command.h"

#include <utility>

Command::Command(std::string name, std::string says) {
    call = std::move(name);
    text = std::move(says);
}

void Command::run() {
    printf("%s\n", text.c_str());
}

bool Command::matches(const std::string& string) {
    return string.rfind(call, 0) == 0;
}
