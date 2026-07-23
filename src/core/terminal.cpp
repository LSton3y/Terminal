#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "core/terminal.h"
#include "core/myparser.h"
#include "core/myexecuter.h"


// Initialise to nullptr
Terminal* Terminal::instance = nullptr;


Terminal::Terminal()
{

}

Terminal::~Terminal()
{
    instance == nullptr;
}


bool Terminal::doesNotExist()
{
    return instance == nullptr;
}


Terminal* Terminal::getInstance()
{
    if (doesNotExist())
    {
        instance = new Terminal();
    }

    return instance;
}


void Terminal::main()
{
    // Initialise parser
    Parser parser = Parser();

    // Initialise executer
    Executer executer = Executer();

    isRunning = true;

    while (isRunning)
    {
        // Read command from user
        std::string command;
        std::cout << "$ ";
        std::getline(std::cin, command);

        // Parse command
        std::vector<std::string> parsedCommand;

        try
        {
            parsedCommand = parser.parse(command);
        }
        catch (const std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
            continue;
        }


        // Execute command
        executer.execute(parsedCommand);
    }
}


void Terminal::exit()
{
    isRunning = false;
}
