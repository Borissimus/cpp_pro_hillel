#include <iostream>
#include <filesystem>
#include <string>
#include <unordered_map>

namespace fs = std::filesystem;

int main() {
    std::string dirPath;
    std::cout << "Введіть шлях до директорії для аналізу: ";
    std::cin >> dirPath;

    fs::path pathToAnalyze(dirPath);

    if (!fs::exists(pathToAnalyze) || !fs::is_directory(pathToAnalyze)) {
        std::cerr << "Некоректний шлях або це не директорія." << std::endl;
        return 1;
    }

	// Counters for different types of files
	int textFileCount = 0;
	int imageFileCount = 0;
	int executableFileCount = 0;
	int otherFileCount = 0;

	// Memory sizes occupied by files
	uintmax_t textFileSize = 0;
	uintmax_t imageFileSize = 0;
	uintmax_t executableFileSize = 0;
	uintmax_t otherFileSize = 0;

	// Iterate through all files in the directory
    for (const auto& entry : fs::recursive_directory_iterator(pathToAnalyze)) {
        if (fs::is_regular_file(entry.path())) {
            auto fileSize = fs::file_size(entry.path());
            std::string extension = entry.path().extension().string();

            if (extension == ".txt") {
                textFileCount++;
                textFileSize += fileSize;
            } else if (extension == ".jpg" || extension == ".png" || extension == ".bmp") {
                imageFileCount++;
                imageFileSize += fileSize;
            } else if (extension == ".exe" || extension == ".bin") {
                executableFileCount++;
                executableFileSize += fileSize;
            } else {
                otherFileCount++;
                otherFileSize += fileSize;
            }
        }
    }

	// Output the results
    std::cout << "Кількість текстових файлів (.txt): " << textFileCount 
			  << ", Загальний обсяг пам'яті: " << textFileSize << " байт" << std::endl;
    std::cout << "Кількість зображень (.jpg, .png, .bmp): " << imageFileCount 
			  << ", Загальний обсяг пам'яті: " << imageFileSize << " байт" << std::endl;
    std::cout << "Кількість виконуваних файлів (.exe, .bin): " << executableFileCount 
			  << ", Загальний обсяг пам'яті: " << executableFileSize << " байт" << std::endl;
    std::cout << "Кількість інших типів файлів: " << otherFileCount 
		      << ", Загальний обсяг пам'яті: " << otherFileSize << " байт" << std::endl;

    return 0;
}
