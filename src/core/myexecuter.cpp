#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

#include "core/myexecuter.h"
#include "commands/echo.h"
#include "commands/exit.h"
#include "commands/help.h"
#include "commands/clear.h"


// Type alias for parsed command
using vec_str = std::vector<std::string>;

// Type alias for commands functions
using map_func = std::unordered_map<std::string, std::function<void(const vec_str&)>>;


Executer::Executer()
{
    // Lambdas for each command
    commands["echo"] = [](const vec_str& params) {
        Echo::echo(params);
        };

    commands["exit"] = [](const vec_str& params) {
        Exit::exit();
        };

    commands["help"] = [](const vec_str& params) {
        Help::help();
        };

    commands["clear"] = [](const vec_str& params) {
        Clear::clear();
        };
}


void Executer::execute(const vec_str& command)
{
    // Find the command in commands
    auto it = commands.find(command[0]);

    if (it != commands.end())
    {
        // Get only the parameters of the command
        vec_str params = vec_str();

        // Loop through all items except the first
        for (int i = 1; i < command.size(); i++)
        {
            params.push_back(command[i]);
        }

        it->second(params);
    }
}