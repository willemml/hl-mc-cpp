//
// Created by wnuke on 2020-10-17.
//

#ifndef HL_MC_CPP_COMMAND_H
#define HL_MC_CPP_COMMAND_H


#include <list>
#include <string>

class Command {
private:
    std::string name;
public:
    std::function<void(std::list<std::string> args)> runs;
    bool matches(const std::string& string);
    Command(const std::string& name, void runs(std::list<std::string> args));
};


#endif //HL_MC_CPP_COMMAND_H
