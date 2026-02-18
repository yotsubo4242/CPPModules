#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
    char    *endptr;

    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "nanf" << std::endl;
        std::cout << "double: " << "nan" << std::endl;
        return;
    }

    if (literal == "+inff" || literal == "-inff" || literal == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        return;
    }

    if (literal == "+inf" || literal == "-inf" || literal == "inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }

    if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]))
    {
        std::cout << "char: '" << literal[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(3) << static_cast<float>(literal[0]) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(3) << static_cast<double>(literal[0]) << std::endl;
        return;
    }

    long long n = std::strtoll(literal.c_str(), &endptr, 10);
    if (n <= INT_MAX && n >= INT_MIN && *endptr == '\0')
    {
        std::cout << "char: ";
        if (n >= 0 && n <= 127)
        {
            if (std::isprint(static_cast<int>(n)))
                std::cout << "'" << static_cast<char>(n) << "'";
            else
                std::cout << "Non displayable";
        }
        else
            std::cout << "impossible";
        std::cout << std::endl;
        std::cout << "int: " << n << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(3) << static_cast<float>(n) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(3) << static_cast<double>(n) << std::endl;
        return;
    }

    double d = std::strtod(literal.c_str(), &endptr);
    if ((*endptr == 'f' || *endptr == 'F') && *(endptr + 1) == '\0')
    {
        std::cout << "char: ";
        if (d >= 0 && d <= 127 && std::isprint(static_cast<int>(d)))
            std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
        else if (d >= 0 && d <= 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "impossible" << std::endl;
        std::cout << "int: ";
        if (d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX))
            std::cout << static_cast<int>(d) << std::endl;
        else
            std::cout << "impossible" << std::endl;
        std::cout << "float: ";
        if (std::isinf(d) || std::isnan(d) || (d >= -FLT_MAX && d <= FLT_MAX))
            std::cout << std::fixed << std::setprecision(3) << static_cast<float>(d) << "f" << std::endl;
        else
            std::cout << "impossible" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(3) << d << std::endl;
        return;
    }

    if (*endptr == '\0')
    {
        std::cout << "char: ";
        if (d >= 0 && d <= 127 && std::isprint(static_cast<int>(d)))
            std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
        else if (d >= 0 && d <= 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "impossible" << std::endl;
        std::cout << "int: ";
        if (d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX))
            std::cout << static_cast<int>(d) << std::endl;
        else
            std::cout << "impossible" << std::endl;
        std::cout << "float: ";
        if (std::isinf(d) || std::isnan(d) || (d >= -FLT_MAX && d <= FLT_MAX))
            std::cout << std::fixed << std::setprecision(3) << static_cast<float>(d) << "f" << std::endl;
        else
            std::cout << "impossible" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(3) << d << std::endl;
        return;
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
