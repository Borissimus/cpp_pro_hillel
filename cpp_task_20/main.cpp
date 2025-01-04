#include <iostream>
#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/optional.hpp>

boost::optional<size_t> getFileSize(const std::string& path) {
    boost::filesystem::path filePath(path);
    if (boost::filesystem::exists(filePath) && boost::filesystem::is_regular_file(filePath)) {
        return boost::filesystem::file_size(filePath);
    }
    return boost::none;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Будь ласка, введіть шляхи до файлів." << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        std::string filePath = argv[i];
        boost::optional<size_t> fileSize = getFileSize(filePath);

        if (fileSize) {
            std::cout << "Файл " << filePath << " існує і його розмір: " << *fileSize << " байтів." << std::endl;
        } else {
            std::cout << "Файл " << filePath << " відсутній." << std::endl;
        }
    }

    return 0;
}
