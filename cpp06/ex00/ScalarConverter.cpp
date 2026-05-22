#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::edgecaseConverter(const std::string& literal) {
    if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
    {
        std::cout << "char: '" << literal[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(literal[0]) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(literal[0]) << std::endl;
        return true;
    }
    return false;
}

bool ScalarConverter::isValidLiteral(const std::string& literal) {
    char *endptr = NULL;
    if (literal.empty())
        return false;
    (void)std::strtod(literal.c_str(), &endptr);
    return (*endptr == '\0' || (*endptr == 'f' && *(endptr + 1) == '\0') || (*endptr == 'F' && *(endptr + 1) == '\0'));
}

void ScalarConverter::charConverter(const std::string& literal) {
    if (!isValidLiteral(literal))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    long l = std::strtol(literal.c_str(), NULL, 10);
    if (literal.length() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])) && std::isprint(static_cast<unsigned char>(literal[0])))
        std::cout << "char: '" << literal[0] << "'" << std::endl;
    else if (l >= 0 && l <= 127 && std::isprint(static_cast<unsigned char>(l)))
        std::cout << "char: '" << static_cast<char>(l) << "'" << std::endl;
    else if (l >= 0 && l <= 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    return ;
}

void ScalarConverter::intConverter(const std::string& literal) {
    if (!isValidLiteral(literal))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    double d = std::strtod(literal.c_str(), NULL);
    if (d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX))
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    return ;
}

void ScalarConverter::floatConverter(const std::string& literal) {
    if (!isValidLiteral(literal))
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }
    double d = std::strtod(literal.c_str(), NULL);
    if (std::isinf(d) || std::isnan(d) || (d >= -FLT_MAX && d <= FLT_MAX))
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;
    return ;

}

void ScalarConverter::doubleConverter(const std::string& literal) {
    if (!isValidLiteral(literal))
    {
        std::cout << "double: impossible" << std::endl;
        return;
    }
    double d = std::strtod(literal.c_str(), NULL);
    if (std::isinf(d) || std::isnan(d) || (d >= -DBL_MAX && d <= DBL_MAX))
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    else
        std::cout << "double: impossible" << std::endl;
    return ;
}

void ScalarConverter::convert(const std::string& literal)
{
    if (edgecaseConverter(literal))
        return;
    charConverter(literal);
    intConverter(literal);
    floatConverter(literal);
    doubleConverter(literal);
    return ;
}
