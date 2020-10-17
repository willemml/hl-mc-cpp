//
// Created by wnuke on 2020-10-16.
//

#ifndef HL_MC_CPP_CLI_H
#define HL_MC_CPP_CLI_H


#include <string>
#include <list>
#include "Command.h"

class CLI {
private:
    std::list<Command> commands;
    static void prompt();
public:
    void loop();
    void setup();
    void run(const std::string& name, const std::list<std::string>& args);
};


#endif //HL_MC_CPP_CLI_H
