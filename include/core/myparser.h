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

    // Splits commands
    vec_str splitCommand(
        const std::string& command,
        bool quoteOpened = false,
        const char& qType = '\0',
        const std::string& initialWord = ""
    );

    // Checks parsed commands
    bool isCommandValid(const vec_str& command);

public:
    vec_str parse(const std::string& command);
};
