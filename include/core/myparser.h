#pragma once

#include <string>
#include <vector>


using vec_str = std::vector<std::string>;

// Parser class
class Parser
{
private:
    // Valid commands
    const vec_str validCommands = {
        "echo",
        "yes",
        "exit",
        "help",
        "clear",
        "meow"
    };

    // Split commands
    vec_str splitCommand(const std::string& command);

    // Checks parsed commands
    bool isCommandValid(const vec_str& command);

public:
    vec_str parse(const std::string& command);
};
