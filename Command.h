//
// Created by wnuke on 2020-10-16.
//

#ifndef HL_MC_CPP_COMMAND_H
#define HL_MC_CPP_COMMAND_H


#include <string>

class Command {
private:
    std::string text;
    std::string call;
public:
    void run();
    bool matches(const std::string& string);
    Command(std::string name, std::string says);
};


#endif //HL_MC_CPP_COMMAND_H
