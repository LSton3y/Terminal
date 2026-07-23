#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include "core/myparser.h"


// Type alias for parsed command
using vec_str = std::vector<std::string>;

const char SPACE{ ' ' };
const std::string EMPTYSTRING{ "" };
const char SINGLEQUOTE{ '\'' };
const char DOUBLEQUOTE{ '"' };


vec_str Parser::parse(const std::string& command)
{
    // Split command
    vec_str parsedCommand = splitCommand(command);

    // Check if command is valid
    if (!isCommandValid(parsedCommand))
    {
        throw std::runtime_error(parsedCommand[0] + " is an invalid command.");
    }

    // Return parsed command
    return parsedCommand;
}


vec_str Parser::splitCommand(const std::string& command)
{
    // Split command
    vec_str parsed = vec_str();
    std::string currentWord = EMPTYSTRING;

    // Iterate through each letter
    for (char c : command)
    {
        // If letter is a space, add current word to parsed
        if (c == SPACE)
        {
            // Only add word if it isn't empty
            if (currentWord != EMPTYSTRING)
                parsed.push_back(currentWord);

            // Reset current word
            currentWord = EMPTYSTRING;
        }
        // Else, add lowercase letter to current word
        else
        {
            currentWord += (char)std::tolower(c);
        }
    }

    // Add final word to parsed
    parsed.push_back(currentWord);

    return parsed;
}


bool Parser::isCommandValid(const vec_str& command)
{
    // Check if command is empty
    if (command[0] == EMPTYSTRING)
    {
        return true;
    }

    // Loop through all the valid commands
    for (std::string cmd : validCommands)
    {
        // Check if the command matches a valid command
        if (command[0] == cmd)
        {
            return true;
        }
    }

    return false;
}
