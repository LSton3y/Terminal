#include <cstdlib>
#include "commands/clear.h"


void Clear::clear()
{
#if defined(_WIN32) || defined(_WIN64)
    std::system("cls"); // Windows
#else
    std::system("clear"); // Linux / macOS
#endif
}