#include <iostream>
#include "commands/help.h"


void Help::help()
{
    std::cout << "List of commands" << std::endl <<
        "   - echo: Terminal outputs parameter" << std::endl <<
        "   - exit: Exit terminal" << std::endl;
}