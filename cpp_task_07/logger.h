#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <mutex>
#include <map>
#include <initializer_list>
#include <sstream>

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance; // Guaranteed to be destroyed and instantiated on first use
        return instance;
    }

    // Prevent copying
    Logger(Logger const&) = delete;
    void operator=(Logger const&) = delete;

    void log(const std::string message, const std::string& level = "INFO") {
        std::lock_guard<std::mutex> guard(log_mutex); // Ensure thread safety

        std::ofstream logFile("build/log.txt", std::ios::app);
        if (logFile.is_open()) {
            logFile << getCurrentTime() << " [" << level << "] - " << message << std::endl;
            logFile.close();
        } else {
            std::cerr << "Error opening log file." << std::endl;
        }
    }

    template <typename Container>
    void logContainer(const Container& container, const std::string& level = "INFO") {
        std::ostringstream oss;
        for (const auto& elem : container) {
            oss << elem << " ";
        }
        log("Container: " + oss.str(), level);
    }

    template <typename T>
    void logContainer(const std::initializer_list<T>& ilist, const std::string& level = "INFO") {
        std::ostringstream oss;
        for (const auto& elem : ilist) {
            oss << elem << " ";
        }
        log("Initializer_list: " + oss.str(), level);
    }

private:
    Logger() {}

    std::string getCurrentTime() const {
        auto now = std::chrono::system_clock::now();
        auto time_t_now = std::chrono::system_clock::to_time_t(now);
        char buffer[100];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&time_t_now));
        return std::string(buffer);
    }

    mutable std::mutex log_mutex; // Mutex for thread safety
};

#endif // LOGGER_H
