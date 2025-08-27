#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

#include <sstream>

// Convert string to int
int toInt(const std::string& str) {
    int result = 0;
    std::stringstream ss(str);
    ss >> result;
    return result;
}

// Convert string to float
float toFloat(const std::string& str) {
    float result = 0.0f;
    std::stringstream ss(str);
    ss >> result;
    return result;
}

// Convert string to double
double toDouble(const std::string& str) {
    double result = 0.0;
    std::stringstream ss(str);
    ss >> result;
    return result;
}


#include <iomanip> // make sure this is included for std::fixed and std::setprecision

void ScalarConverter::convert(std::string str)
{
    std::cout << toInt(str) << std::endl;

    std::cout << std::fixed << std::setprecision(1) << toFloat(str) << "f" << std::endl;

    std::cout << std::fixed << std::setprecision(1) << toDouble(str) << std::endl;
}



