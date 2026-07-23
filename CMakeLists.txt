cmake_minimum_required(VERSION 3.10)

project(Terminal VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MyProject
    src/main.cpp

    src/core/myexecuter.cpp
    src/core/myparser.cpp
    src/core/terminal.cpp
    
    src/commands/echo.cpp
    src/commands/exit.cpp
    src/commands/help.cpp
    src/commands/clear.cpp
    src/commands/meow.cpp
)

# Tell CMake where your header files are located
target_include_directories(MyProject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
