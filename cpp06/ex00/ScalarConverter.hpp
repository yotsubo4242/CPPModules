#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <climits>
# include <cfloat>
# include <cstdlib>
# include <cctype>
# include <iomanip>

class ScalarConverter
{
    public:
        static void convert(const std::string& literal);
    private:
        static bool isValidLiteral(const std::string& literal);
        static bool edgecaseConverter(const std::string& literal);
        static void charConverter(const std::string& literal);
        static void intConverter(const std::string& literal);
        static void floatConverter(const std::string& literal);
        static void doubleConverter(const std::string& literal);
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
};

#endif
