#include <iostream>
#include "logger.h"
#include "config_manager.h"

int main() {
    // Example usage of Logger
    Logger::getInstance().log("This is an info message");
    Logger::getInstance().log("This is a warning message", "WARNING");
    Logger::getInstance().log("This is an error message", "ERROR");

    // Example usage of ConfigManager
    ConfigManager::getInstance().setConfig("username", "user123");
    ConfigManager::getInstance().setConfig("password", "pass123");

    std::cout << ConfigManager::getInstance().getConfig("username") << std::endl; // Output: user123
    std::cout << ConfigManager::getInstance().getConfig("missing_key") << std::endl; // Output: Key not found

    return 0;
}

