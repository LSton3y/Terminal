#pragma once

#include <unordered_map>
#include <functional>
#include <string>
#include <vector>


// Type alias for parsed command
using vec_str = std::vector<std::string>;

// Type alias for commands functions
using map_func = std::unordered_map<std::string, std::function<void(const vec_str&)>>;


class Executer
{
private:
    map_func commands;

public:
    Executer();
    void execute(const vec_str& command);
};