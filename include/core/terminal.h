#pragma once


class Terminal
{
private:
    static Terminal* instance;
    Terminal();

    // Running variable
    bool isRunning;

public:
    ~Terminal();

    Terminal(const Terminal&) = delete;
    Terminal& operator=(const Terminal&) = delete;

    // Prevent moving the singleton instance
    Terminal(Terminal&&) = delete;
    Terminal& operator=(Terminal&&) = delete;

    // Returns true if no instance has been created yet
    static bool doesNotExist();

    // Retrieves the active instance or creates one if empty
    static Terminal* getInstance();

    // Main method
    void main();

    // Exit method
    void exit();
};