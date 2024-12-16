#include "main.h"

int main() {
    int choice;
    double value;
    std::string from, to;

    std::cout << "Виберіть тип конвертації:\n1. Довжина\n2. Маса\n3. Температура\n";
    std::cin >> choice;

	displayValidUnits(choice);

    std::cout << "Введіть значення для конвертації: ";
    std::cin >> value;

    std::cout << "Введіть одиницю вимірювання (from): ";
    std::cin >> from;

    std::cout << "Введіть одиницю вимірювання (to): ";
    std::cin >> to;

    try {
        double result;
        switch (choice) {
            case 1:
                result = convert<ConversionType::Length>(value, from, to);
                break;
            case 2:
                result = convert<ConversionType::Mass>(value, from, to);
                break;
            case 3:
                result = convert<ConversionType::Temperature>(value, from, to);
                break;
            default:
                std::cout << "Неправильний вибір." << std::endl;
                return 1;
        }
        std::cout << "Результат: " << result << " " << to << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
