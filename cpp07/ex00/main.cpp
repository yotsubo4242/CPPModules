#include "whatever.hpp"
#include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RES "\033[0m"

int main( void )
{
    int a = 2;
    int b = 3;

    std::cout << GREEN << "Integer test" << RES << std::endl;
    std::cout << YELLOW << "Before swap: " << RES << "a = " << a << ", b = " << b << std::endl;
    ::swap( a, b );
    std::cout << YELLOW << "After swap: " << RES << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::cout << std::endl << GREEN << "String test" << RES << std::endl;
    std::string c = "Hello";
    std::string d = "World";
    std::cout << YELLOW << "Before swap: " << RES << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << YELLOW << "After swap: " << RES << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    std::cout << std::endl << GREEN << "Float test" << RES << std::endl;
    float e = 1.5f;
    float f = 2.5f;
    std::cout << YELLOW << "Before swap: " << RES << "e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);
    std::cout << YELLOW << "After swap: " << RES << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
    std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

    std::cout << std::endl << GREEN << "Double test" << RES << std::endl;
    double g = 1.5;
    double h = 2.5;
    std::cout << YELLOW << "Before swap: " << RES << "g = " << g << ", h = " << h << std::endl;
    ::swap(g, h);
    std::cout << YELLOW << "After swap: " << RES << "g = " << g << ", h = " << h << std::endl;
    std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
    std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;
    
    return 0;
}