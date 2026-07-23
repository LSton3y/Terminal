#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

#include "core/myparser.h"
#include "core/terminal.h"


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


vec_str Parser::splitCommand(
    const std::string& command,
    bool quoteOpened,
    const char& qType,
    const std::string& initalWord
)
{
    vec_str parsed;
    std::string currentWord{ initalWord };

    bool openQuote{ quoteOpened };
    char quoteType{ qType };

    // Loop through each letter in command
    for (char c : command)
    {
        // Checks if letter is space and not in a quote
        if (c == SPACE && !openQuote)
        {
            // Add to parsed if not empty
            if (!currentWord.empty())
            {
                parsed.push_back(currentWord);
            }
            currentWord.clear();
        }
        // Check if quote and matches current quote type (or if not in a quote)
        else if ((c == SINGLEQUOTE || c == DOUBLEQUOTE) && (!openQuote || c == quoteType))
        {
            if (!openQuote)
            {
                // Opening a quote
                openQuote = true;
                quoteType = c;
            }
            else
            {
                // Closing the quote
                openQuote = false;
                quoteType = '\0';

                parsed.push_back(currentWord);
                currentWord.clear();
            }
        }
        // Adds generic letters to the words (makes them lowercase if first command)
        else
        {
            currentWord += c;
        }
    }

    if (openQuote)
    {
        // Don't push currentWord — hand it off as the seed for the continued word
        vec_str continuation = splitCommand(
            Terminal::getInstance()->query(),
            true,
            quoteType,
            currentWord + "\n"
        );
        for (const std::string& item : continuation)
        {
            parsed.push_back(item);
        }
    }

    // Push last word if not empty
    else if (!currentWord.empty())
    {
        parsed.push_back(currentWord);
    }

    if (parsed.empty())
    {
        parsed.push_back(EMPTYSTRING); // preserve "empty command" case
    }

    return parsed;
}


bool Parser::isCommandValid(const vec_str& command)
{
    // Check if command is empty
    if (command[0].empty())
    {
        return true;
    }

    // Loop through all the valid commands
    for (const std::string& cmd : validCommands)
    {
        // Check if the command matches a valid command
        if (command[0] == cmd)
        {
            return true;
        }
    }

    return false;
}
