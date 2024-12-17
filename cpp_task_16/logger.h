#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <mutex>
#include <map>

#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <mutex>

class Logger {
public:
    static Logger& getInstance() {
        std::lock_guard<std::mutex> lock(mtx); // Lock for thread safety
        if (instance == nullptr) {
            instance = new Logger(); // Create instance if it doesn't exist
        }
        return *instance;
    }

    // Prevent copying
    Logger(Logger const&) = delete;
    void operator=(Logger const&) = delete;

    void log(const std::string& message, const std::string& level = "INFO") {
        std::lock_guard<std::mutex> guard(log_mutex); // Ensure thread safety for logging

        std::ofstream logFile("build/log.txt", std::ios::app);
        if (logFile.is_open()) {
            logFile << getCurrentTime() << " [" << level << "] - " << message << std::endl;
            logFile.close();
        } else {
            std::cerr << "Error opening log file." << std::endl;
        }
    }

private:
    Logger() {} // Private constructor

    static Logger* instance;    // Static instance of the Logger
    static std::mutex mtx;      // Mutex for instance creation
    mutable std::mutex log_mutex; // Mutex for thread-safe log writing

    std::string getCurrentTime() const {
        auto now = std::chrono::system_clock::now();
        auto time_t_now = std::chrono::system_clock::to_time_t(now);
        char buffer[100];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&time_t_now));
        return std::string(buffer);
    }
};

#endif // LOGGER_H
