/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmoud <mahmoud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:20:11 by mahmoud           #+#    #+#             */
/*   Updated: 2024/09/16 21:16:36 by mahmoud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ) 
{ 
    return *this; 
}

void ScalarConverter::convert(const std::string& input) 
{
    char* end;

    // Attempt conversion to double
    double doubleValue = std::strtod(input.c_str(), &end);

    // Check for double specific cases
    if (*end == '\0') 
    {
        // Handle double-specific cases
        if (std::isnan(doubleValue)) 
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: nanf\n";
            std::cout << "double: nan\n";
            return;
        } 
        else if (std::isinf(doubleValue)) 
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: " << (doubleValue > 0 ? "inff\n" : "-inff\n");
            std::cout << "double: " << (doubleValue > 0 ? "inf\n" : "-inf\n");
            return;
        }

        // Handle conversion from double to other types
        std::cout << "char: ";
        if (doubleValue < 32 || doubleValue > 126 || std::isnan(doubleValue) || std::isinf(doubleValue)) 
        {
            std::cout << "impossible\n";
        } 
        else 
        {
            std::cout << "'" << static_cast<char>(doubleValue) << "'\n";
        }
        std::cout << "int: ";
        if (doubleValue < std::numeric_limits<int>::min() || doubleValue > std::numeric_limits<int>::max() || std::isnan(doubleValue) || std::isinf(doubleValue)) 
        {
            std::cout << "impossible\n";
        } 
        else 
        {
            std::cout << static_cast<int>(doubleValue) << "\n";
        }
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(doubleValue) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << "\n";
        return;
    }

    // Attempt conversion to float
    float floatValue = std::strtof(input.c_str(), &end);
    if (*end == 'f' && *(end + 1) == '\0') {
        std::cout << "char: ";
        if (std::isnan(floatValue) || std::isinf(floatValue) || floatValue < 32 || floatValue > 126) 
        {
            std::cout << "impossible\n";
        } 
        else 
        {
            std::cout << "'" << static_cast<char>(floatValue) << "'\n";
        }
        std::cout << "int: ";
        if (floatValue < std::numeric_limits<int>::min() || floatValue > std::numeric_limits<int>::max()) 
        {
            std::cout << "impossible\n";
        } 
        else 
        {
            std::cout << static_cast<int>(floatValue) << "\n";
        }
        std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(floatValue) << "\n";
        return;
    }

    // Attempt conversion to integer
    long intValue = std::strtol(input.c_str(), &end, 10);
    if (*end == '\0' && intValue >= std::numeric_limits<int>::min() && intValue <= std::numeric_limits<int>::max()) 
    {
        std::cout << "char: ";
        if (intValue < 32 || intValue > 126) 
        {
            std::cout << "Non displayable\n";
        } 
        else 
        {
            std::cout << "'" << static_cast<char>(intValue) << "'\n";
        }

        std::cout << "int: " << intValue << "\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(intValue) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(intValue) << "\n";
        return;
    }

    // If no valid conversion was possible
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}