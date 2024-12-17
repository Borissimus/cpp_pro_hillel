#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>

enum class ConversionType { Length, Mass, Temperature };

template<ConversionType Type>
double convert(double value, const std::string& from, const std::string& to) {
    if constexpr (Type == ConversionType::Length) {
        if (from == "m" && to == "km") return value / 1000.0;
        else if (from == "km" && to == "m") return value * 1000.0;
        else if (from == "mm" && to == "m") return value / 1000.0;
        else if (from == "m" && to == "mm") return value * 1000.0;
    }
    else if constexpr (Type == ConversionType::Mass) {
        if (from == "kg" && to == "g") return value * 1000.0;
        else if (from == "g" && to == "kg") return value / 1000.0;
        else if (from == "lb" && to == "kg") return value * 0.453592;
        else if (from == "kg" && to == "lb") return value / 0.453592;
    }
    else if constexpr (Type == ConversionType::Temperature) {
        if (from == "C" && to == "F") return value * 9.0 / 5.0 + 32.0;
        else if (from == "F" && to == "C") return (value - 32.0) * 5.0 / 9.0;
    }
    throw std::invalid_argument("Invalid conversion parameters");
}

void displayValidUnits(int choice) {
    std::cout << "Допустимі одиниці вимірювання:\n";
    switch (choice) {
        case 1:
            std::cout << "Довжина: mm, m, km\n";
            break;
        case 2:
            std::cout << "Маса: g, kg, lb\n";
            break;
        case 3:
            std::cout << "Температура: C, F\n";
            break;
        default:
            std::cout << "Неправильний вибір." << std::endl;
            break;
    }
}

#endif // MAIN_H
