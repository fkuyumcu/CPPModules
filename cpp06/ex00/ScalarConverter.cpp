#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <iomanip>


static bool isChar(const std::string &literal)
{
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

static bool isInt(const std::string &literal)
{
    size_t i = 0;
    if(literal.empty())
        return false;

    if (literal[i] == '-' || literal[i] == '+')
    {
        i++;
    }

    if (i == literal.length()) return false;

    while (i < literal.length()) {
        if (!std::isdigit(literal[i])) {
            return false;
        }
        i++;
    }

    return true;
}

static bool isFloat(const std::string &literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;

    if (literal.empty() || literal[literal.length() - 1] != 'f')
        return false;

    size_t i = 0;
    bool dotFound = false;

    if (literal[i] == '-' || literal[i] == '+')
        i++;

    for (; i < literal.length() - 1; i++)
    {
        if (literal[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (!std::isdigit(literal[i]))
        {
            return false;
        }
    }
    return true;
}

static bool isDouble(const std::string &literal)
{
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
    int count = 0;
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') 
            count++;
        else if (!isdigit(literal[i]))
            return false;
    }
    return count == 1;
}

static void printChar(double val)
{
    if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127)
        std::cout << "char: impossible" << std::endl;
    else if (val < 32 || val > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
}

static void printInt(double val)
{
    if (std::isnan(val) || std::isinf(val) || 
        val < std::numeric_limits<int>::min() || 
        val > std::numeric_limits<int>::max()) 
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
}

static void printFloat(double val)
{
    float f = static_cast<float>(val);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void printDouble(double val)
{
    std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
        double value = 0;

    if (isChar(literal)) {
        value = static_cast<double>(literal[1]);
    }
    else if (isInt(literal)) {
        value = std::atof(literal.c_str());
    }
    else if (isFloat(literal)) {
        if (literal == "-inff") value = -std::numeric_limits<double>::infinity();
        else if (literal == "+inff") value = std::numeric_limits<double>::infinity();
        else if (literal == "nanf") value = std::numeric_limits<double>::quiet_NaN();
        else value = std::atof(literal.c_str());
    }
    else if (isDouble(literal)) {
        if (literal == "-inf") value = -std::numeric_limits<double>::infinity();
        else if (literal == "+inf") value = std::numeric_limits<double>::infinity();
        else if (literal == "nan") value = std::numeric_limits<double>::quiet_NaN();
        else value = std::atof(literal.c_str());
    }
    else {
        std::cout << "Error: Invalid literal" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}