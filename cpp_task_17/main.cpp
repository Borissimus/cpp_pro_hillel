#include <iostream>
#include <filesystem>
#include <string>
#include <unordered_map>
#include <thread>
#include <vector>
#include <future>
#include <sstream>
#include <mutex>

namespace fs = std::filesystem;

// Structure to store overall statistics
struct DirectoryStatistics {
    int textFileCount = 0;
    uintmax_t textFileSize = 0;
    int imageFileCount = 0;
    uintmax_t imageFileSize = 0;
    int executableFileCount = 0;
    uintmax_t executableFileSize = 0;
    int otherFileCount = 0;
    uintmax_t otherFileSize = 0;
};

// Function to analyze a directory
void analyzeDirectory(const fs::path& path, DirectoryStatistics& stats, std::mutex& statsMutex) {
    // Iterate through all files in the directory
    for (const auto& entry : fs::directory_iterator(path)) {
        try {
            if (fs::is_regular_file(entry.path())) {
                auto fileSize = fs::file_size(entry.path());
                std::string extension = entry.path().extension().string();

                std::lock_guard<std::mutex> guard(statsMutex); // Ensure thread safety for stats update

                if (extension == ".txt") {
                    stats.textFileCount++;
                    stats.textFileSize += fileSize;
                } else if (extension == ".jpg" || extension == ".png" || extension == ".bmp") {
                    stats.imageFileCount++;
                    stats.imageFileSize += fileSize;
                } else if (extension == ".exe" || extension == ".bin") {
                    stats.executableFileCount++;
                    stats.executableFileSize += fileSize;
                } else {
                    stats.otherFileCount++;
                    stats.otherFileSize += fileSize;
                }
            } else if (fs::is_directory(entry.path())) {
                // If the entry is a directory and not a symlink
                if (!fs::is_symlink(entry.path())) {
                    analyzeDirectory(entry.path(), stats, statsMutex);
                }
            }
        } catch (const fs::filesystem_error& e) {
            std::cerr << "Error accessing file or directory: " << e.what() << std::endl;
            continue; // Skip this entry
        }
    }
}

int main() {
    std::string dirPath;
    std::cout << "Введіть шлях до директорії для аналізу: ";
    std::cin >> dirPath;

    fs::path pathToAnalyze(dirPath);

    if (!fs::exists(pathToAnalyze) || !fs::is_directory(pathToAnalyze)) {
        std::cerr << "Некоректний шлях або це не директорія." << std::endl;
        return 1;
    }

    DirectoryStatistics totalStats;
    std::vector<std::future<void>> futures;
    std::mutex statsMutex;

    // Create a thread for each immediate subdirectory in the pathToAnalyze
    for (const auto& entry : fs::directory_iterator(pathToAnalyze)) {
        if (fs::is_directory(entry.path()) && !fs::is_symlink(entry.path())) {
            futures.push_back(std::async(std::launch::async, analyzeDirectory, entry.path(), std::ref(totalStats), std::ref(statsMutex)));
        }
    }

    // Handle the analysis of files in the main directory
    analyzeDirectory(pathToAnalyze, totalStats, statsMutex);

    // Wait for all threads to complete
    for (auto& future : futures) {
        future.get();
    }

    // Output the total results
    std::cout << "Загальна інформація по файлів у директорії '" << dirPath << "':" << std::endl;
    std::cout << "Кількість текстових файлів (.txt): " << totalStats.textFileCount 
              << ", Загальний обсяг пам'яті: " << totalStats.textFileSize << " байт" << std::endl;
    std::cout << "Кількість зображень (.jpg, .png, .bmp): " << totalStats.imageFileCount 
              << ", Загальний обсяг пам'яті: " << totalStats.imageFileSize << " байт" << std::endl;
    std::cout << "Кількість виконуваних файлів (.exe, .bin): " << totalStats.executableFileCount 
              << ", Загальний обсяг пам'яті: " << totalStats.executableFileSize << " байт" << std::endl;
    std::cout << "Кількість інших типів файлів: " << totalStats.otherFileCount 
              << ", Загальний обсяг пам'яті: " << totalStats.otherFileSize << " байт" << std::endl;

    return 0;
}