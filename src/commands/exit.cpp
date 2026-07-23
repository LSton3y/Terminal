#include <vector>
#include <string>
#include <iostream>
#include "commands/exit.h"
#include "core/terminal.h"

// Type alias for parsed command
using vec_str = std::vector<std::string>;


void Exit::exit()
{
    // Get terminal instance
    Terminal::getInstance()->exit();
}