#include <iostream>
#include "logger.h"

// Initialize static members
Logger* Logger::instance = nullptr;
std::mutex Logger::mtx;

int main() {
    // Example usage of Logger
    Logger::getInstance().log("This is an info message");
    Logger::getInstance().log("This is a warning message", "WARNING");
    Logger::getInstance().log("This is an error message", "ERROR");

	std::cout << "Logs written to the file." << std::endl;

    return 0;
}

