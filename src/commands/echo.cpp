#include <vector>
#include <string>
#include <iostream>
#include "commands/echo.h"

// Type alias for parsed command
using vec_str = std::vector<std::string>;


void Echo::echo(const vec_str& params)
{
    // Output each parameter
    for (std::string item : params)
    {
        std::cout << item << std::endl;
    }
}